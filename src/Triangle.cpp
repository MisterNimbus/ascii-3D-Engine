#include "./include/Triangle.h"
#include "./include/Engine.h"
#include "include/Point.h"
#include "include/mathUtils.h"
#include <cmath>
#include <iostream>
#include <iterator>
#include <math.h>
#include <ostream>
#include <vector>



std::vector<std::string> surfaceChars2 ={"1","2","3","4","5"};

std::vector<std::string> surfaceChars ={
                                            //".:-=+*",
                                        //",~<#%@",
                                        //"..........::::::::::----------==========++++++++++********************++++++++++==========----------:::::::::........."};
        "....:::==##@##==:::...."};


// For setting the starting value of unique triangle Ids to 0.
int Triangle::nextId = 0;

// Buffer for storing the absolute Position of each point which is not relative
// to the anchor butt rather to the origin of the coordinate system.
Triangle absolutePosition(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

// Buffer for storing the position of each point after being multiplied by the
// projection matrix.
Triangle projectionBuffer(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

// Buffer for storing the position of each point on the screen. Rounded to a int
// and offsets are added to center the image.
Triangle projectionBufferScreenIndex(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 0.0f);

// Buffer for storing the position of the anchor after being multiplied by the
// projection matrix.
Point *anchorProjection = new Point(0.0f, 0.0f, 0.0f);

Triangle::Triangle() : surfaceChar('#') {
  this->id = nextId;
  Triangle::nextId++;
};

Triangle::Triangle(Triangle *triangle, char surfaceChar)
    : surfaceChar(surfaceChar) {
  this->id = nextId;
  Triangle::nextId++;
  this->points[0] = new Point(triangle->points[0]);
  this->points[1] = new Point(triangle->points[1]);
  this->points[2] = new Point(triangle->points[2]);
}

Triangle::Triangle(Point *p1, Point *p2, Point *p3, char surfaceChar)
    : surfaceChar(surfaceChar) {
  this->id = nextId;
  Triangle::nextId++;
  this->points[0] = p1;
  this->points[1] = p2;
  this->points[2] = p3;
};

Triangle::Triangle(float p1x, float p1y, float p1z, float p2x, float p2y,
                  float p2z, float p3x, float p3y, float p3z, char surfaceChar)
    : surfaceChar(surfaceChar) {
  this->id = nextId;
  Triangle::nextId++;
  this->points[0] = new Point(p1x, p1y, p1z);
  this->points[1] = new Point(p2x, p2y, p2z);
  this->points[2] = new Point(p3x, p3y, p3z);
};

Triangle::~Triangle(){};

Point *Triangle::getPoints() { return *points; }

Point *Triangle::getPoint(int index) { return points[index]; }

int Triangle::getId() { return this->id; }
char Triangle::getSurfaceChar() { return this->surfaceChar; }

Triangle *Triangle::getRotatedTriangle(rotationVector rotation) {
  Triangle *result = new Triangle(this);
  result->rotate(rotation);
  return result;
}

vec3x1 Triangle::getNormal() {
  vec3x1 vec01 =
      this->points[0]->getPosition() - this->points[1]->getPosition();
  vec3x1 vec02 =
      this->points[0]->getPosition() - this->points[2]->getPosition();
  vec3x1 result = vec01.crossProduct(vec02);
  result /= result.length();
  return result;
}

char Triangle::getOrientedSurfaceChar(std::vector<std::string> surfaceChars){
  vec3x1 normalInSpherical = this->getNormal().convertToSphericalCoordinates();
  float inclinationStep = 180.f / surfaceChars.at(0).length();
  int inclinationIndex = ( normalInSpherical.y / inclinationStep);
  //std::cout << "inclination: " << normalInSpherical.y << " azimuth: " << normalInSpherical.z << "\n";
  normalInSpherical.z = (int) (normalInSpherical.z)% 90;
  int azimuthStep = 90/surfaceChars.size();
  
  int azimuthIndex = (int) std::abs(normalInSpherical.z / azimuthStep)%surfaceChars.at(0).length();
  //std::cout << "azimuthIndex: " << azimuthIndex << "  inclinationIndex: " << inclinationIndex << "  \n";
  return surfaceChars[azimuthIndex][inclinationIndex];
}

void Triangle::rotate(rotationVector rotation) {
  for (auto point : this->points) {
    point->rotate(rotation);
  }
}

void Triangle::update(Engine *engine, float tick, Point *meshAnchor,
                      rotationVector rotation) {
  this->rotate(rotation);
};

void Triangle::drawLine(Engine *engine, char lineChar, Point &p1, Point &p2,
                        int resolution) {
  std::vector<Point *> linePoints;
  float difX = p2.getPositionX() - p1.getPositionX();
  float difY = p2.getPositionY() - p1.getPositionY();
  float difZ = p2.getPositionZ() - p1.getPositionZ();
  for (int i = 0; i <= resolution; i++) {
    linePoints.push_back(new Point(p1.getPositionX() + i * difX / resolution,
                                   p1.getPositionY() + i * difY / resolution,
                                   p1.getPositionZ() + i * difZ / resolution));
  }
  for (auto point : linePoints) {
    if (point->getPositionX() + point->getPositionY() * SCREEN_WIDTH >= 0 &&
        point->getPositionX() + point->getPositionY() * SCREEN_WIDTH <
            SCREEN_WIDTH * SCREEN_HEIGHT) {
      if (point->getPositionZ() >
          engine->zBuffer[(int)point->getPositionX() +
                          (int)point->getPositionY() * SCREEN_WIDTH]) {
        engine->zBuffer[(int)point->getPositionX() +
                        (int)point->getPositionY() * SCREEN_WIDTH] =
            point->getPositionZ();
        engine->screenBuffer[(int)point->getPositionX() +
                             (int)point->getPositionY() * SCREEN_WIDTH] =
            lineChar;
      }
    }
  }
};

void Triangle::draw(Engine *engine, Point *meshAnchor) {

  // Applies the Anchor Offset to the points.
  absolutePosition.points[0] = this->points[0]->applyAnchorOffset(*meshAnchor);
  absolutePosition.points[1] = this->points[1]->applyAnchorOffset(*meshAnchor);
  absolutePosition.points[2] = this->points[2]->applyAnchorOffset(*meshAnchor);

  // absolutePosition.log();

  // Applies Projection Matrix and stores resulting triangle in projectionBuffer
  engine->multiplyProjectionMatrix(*absolutePosition.points[0],
                                   *projectionBuffer.points[0],
                                   *engine->getProjectionMatrix());
  engine->multiplyProjectionMatrix(*absolutePosition.points[1],
                                   *projectionBuffer.points[1],
                                   *engine->getProjectionMatrix());
  engine->multiplyProjectionMatrix(*absolutePosition.points[2],
                                   *projectionBuffer.points[2],
                                   *engine->getProjectionMatrix());

  // Calculating Screen Buffer Index
  projectionBufferScreenIndex.points[0]->setPositionX(
      (int)projectionBuffer.points[0]->getPositionX() * 2 + X_OFFSET);
  projectionBufferScreenIndex.points[0]->setPositionY(
      (int)projectionBuffer.points[0]->getPositionY() + Y_OFFSET);
  projectionBufferScreenIndex.points[0]->setPositionZ(
      projectionBuffer.points[0]->getPositionZ() + Z_OFFSET);

  projectionBufferScreenIndex.points[1]->setPositionX(
      (int)projectionBuffer.points[1]->getPositionX() * 2 + X_OFFSET);
  projectionBufferScreenIndex.points[1]->setPositionY(
      (int)projectionBuffer.points[1]->getPositionY() + Y_OFFSET);
  projectionBufferScreenIndex.points[1]->setPositionZ(
      projectionBuffer.points[1]->getPositionZ() + Z_OFFSET);

  projectionBufferScreenIndex.points[2]->setPositionX(
      (int)projectionBuffer.points[2]->getPositionX() * 2 + X_OFFSET);
  projectionBufferScreenIndex.points[2]->setPositionY(
      (int)projectionBuffer.points[2]->getPositionY() + Y_OFFSET);
  projectionBufferScreenIndex.points[2]->setPositionZ(
      projectionBuffer.points[2]->getPositionZ() + Z_OFFSET);

  // projectionBufferScreenIndex.log();

  for (auto point : projectionBufferScreenIndex.points) {
    if ((int)point->getPositionX() +
                (int)point->getPositionY() * SCREEN_WIDTH >=
            0 &&
        (int)point->getPositionX() + (int)point->getPositionY() * SCREEN_WIDTH <
            SCREEN_WIDTH * SCREEN_HEIGHT) {
      if (point->getPositionZ() >
          engine->zBuffer[(int)point->getPositionX() +
                          (int)point->getPositionY() * SCREEN_WIDTH]) {
        engine->zBuffer[(int)point->getPositionX() +
                        (int)point->getPositionY() * SCREEN_WIDTH] =
            point->getPositionZ();
        engine->screenBuffer[(int)point->getPositionX() +
                             (int)point->getPositionY() * SCREEN_WIDTH] =
            this->surfaceChar;
      }
    }
  }

  // required resolution
  int resolution01 =
      (int)sqrt(pow(projectionBufferScreenIndex.points[0]->getPositionX() -
                        projectionBufferScreenIndex.points[1]->getPositionX(),
                    2) +
                pow((projectionBufferScreenIndex.points[0]->getPositionY() -
                     projectionBufferScreenIndex.points[1]->getPositionY()),
                    2));
  int resolution12 =
      (int)sqrt(pow(projectionBufferScreenIndex.points[1]->getPositionX() -
                        projectionBufferScreenIndex.points[2]->getPositionX(),
                    2) +
                pow((projectionBufferScreenIndex.points[1]->getPositionY() -
                     projectionBufferScreenIndex.points[2]->getPositionY()),
                    2));
  int resolution20 =
      (int)sqrt(pow(projectionBufferScreenIndex.points[2]->getPositionX() -
                        projectionBufferScreenIndex.points[0]->getPositionX(),
                    2) +
                pow((projectionBufferScreenIndex.points[2]->getPositionY() -
                     projectionBufferScreenIndex.points[0]->getPositionY()),
                    2));

  // draw Vertices
  // drawLine(engine,'.',*projectionBufferScreenIndex.points[0],
  // *projectionBufferScreenIndex.points[1], resolution01);
  // drawLine(engine,'.',*projectionBufferScreenIndex.points[1],
  // *projectionBufferScreenIndex.points[2], resolution12);
  // drawLine(engine,'.',*projectionBufferScreenIndex.points[2],
  // *projectionBufferScreenIndex.points[0], resolution20);

  // Fill Triangle
  //fillSurface(engine, projectionBufferScreenIndex, this->surfaceChar,
  //            resolution01, resolution12, resolution20);
  
  fillSurface(engine, projectionBufferScreenIndex, this->getOrientedSurfaceChar(surfaceChars),
              resolution01, resolution12, resolution20);
}

void Triangle::fillSurface(Engine *engine, Triangle projectionBufferScreenIndex,
                           char surfaceChar, int resolution01, int resolution12,
                           int resolution20) {

  Point line01Step = (*projectionBufferScreenIndex.points[1] -
                      *projectionBufferScreenIndex.points[0]) /
                     resolution01;
  Point line02Step = (*projectionBufferScreenIndex.points[2] -
                      *projectionBufferScreenIndex.points[0]) /
                     resolution20;
  Point line12Step = (*projectionBufferScreenIndex.points[2] -
                      *projectionBufferScreenIndex.points[1]) /
                     resolution12;
  for (int i = 0; i <= resolution01; i++) {
    Point lineStart = *projectionBufferScreenIndex.points[0] + (line01Step * i);
    for (int j = 0; j <= resolution20; j++) {
      Point lineEnd = *projectionBufferScreenIndex.points[0] + (line02Step * j);
      drawLine(engine, surfaceChar, lineStart, lineEnd, resolution12);
    }
  }
}

void Triangle::log() {
  std::cout << "\nTriangle ID: " << this->id << "                         \n";
  std::cout << "          Point1 : (" << this->points[0]->getPositionX() << ", "
            << this->points[0]->getPositionY() << ", "
            << this->points[0]->getPositionZ() << ")            \n";
  std::cout << "          Point2 : (" << this->points[1]->getPositionX() << ", "
            << this->points[1]->getPositionY() << ", "
            << this->points[1]->getPositionZ() << ")            \n";
  std::cout << "          Point3 : (" << this->points[2]->getPositionX() << ", "
            << this->points[2]->getPositionY() << ", "
            << this->points[2]->getPositionZ() << ")            \n";
}

void Triangle::setSurfaceChar(char surfaceChar) {
  this->surfaceChar = surfaceChar;
}