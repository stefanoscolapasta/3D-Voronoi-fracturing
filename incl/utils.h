#pragma once
#ifndef UTILS_H 
#define UTILS_H
#include <bullet/LinearMath/btVector3.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include<glm/gtx/norm.hpp>
#include "mesh.h"
#include "camera.h"
#include "tetrahedron.h"

#define N 4
#define SCR_WIDTH 800
#define SCR_HEIGHT  600



//OPENGL UTILS
bool isSimulationStarted();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow* window);
GLFWwindow* createWindow();
Camera getCamera();
void setFrame(float deltaTime_, float lastFrame_);
float getDeltaTime();
float getLastFrame();

//MATHS

//RETURN VALUE:
//>0 -> p is above the plane defined by a, b,c
//<0 -> p is under the plane defined by a, b,c
// = 0-> p is on the plane defined by a, b,c
btVector3 getSphereCenter(std::set<btVector3, btVector3Comparator> points);
glm::vec3 intersection(glm::vec3 normal1, glm::vec3 point1, glm::vec3 normal2, glm::vec3 point2);
int orient(btVector3 a, btVector3 b, btVector3 c, btVector3 p);
float determinantOfMatrix(float matrix[N][N], int n);
void subMatrix(float mat[N][N], float temp[N][N], int p, int q, int n);
btVector3 getTetrahedronCenter(Tetrahedron tetrahedron);
bool isPointInsideSphere(Tetrahedron tetrahedron, btVector3 P);

void fillVertexData(std::vector<float> verticesAsSingleArr, glm::vec3 color, float vertices[]);

//TETRAS
void generateVerticesFromMesh(Mesh meshModel, std::vector<btVector3>& meshVertices);
Tetrahedron CreateTetrahedronAroundShape(std::vector<btVector3> shapeVertices, glm::vec3 meshColor);
bool isFacetInTetrahedron(const Tetrahedron& t, const TriangleFacet& f);
bool areTriangleFacetsEqual(const TriangleFacet& f1, const TriangleFacet& f2);
bool isPointInsideTetrahedron(Tetrahedron tetrahedron, btVector3  point);
bool SameSide(glm::vec3 v0, glm::vec3 v1, glm::vec3 v2, glm::vec3 v3, glm::vec3 p);
std::vector<Tetrahedron> getTetrasIncidentToEdge(btVector3 v1, btVector3 v2, std::vector<Tetrahedron> tetrahedra);
TriangleFacet findSharedFacet(Tetrahedron t1, Tetrahedron t2);

std::vector<btVector3> convertToVector(std::set<btVector3> v);
std::vector<float> convertVertexVectorToFlatFloatArr(std::set<Vertex> allVertices);
std::vector<float> convertVertexVectorToFlatFloatArr(std::vector<Vertex> allVertices);
std::vector<float> convertVertexVectorToFlatFloatArr(std::set<btVector3, btVector3Comparator> allVertices);

void vectorToFloatArray(const std::vector<float>& vec, float arr[]);
std::vector<float> generateVerticesArrayFromVertex(Vertex v);
std::vector<float> generateVerticesArrayFromBtVector3(btVector3 v);
Vertex btVectorToVertex(btVector3 v);
btVector3 fromVertexToBtVector3(Vertex v);
std::set<Vertex> btVectorSetToVertexSet(std::set<btVector3, btVector3Comparator> allVertices);
bool areBtVector3Equal(btVector3 v1, btVector3 v2);

Vertex btVectorToVertex(btVector3 v);
std::vector<float> generateVerticesArrayFromBtVector3(btVector3 v);
btVector3 fromVertexToBtVector3(Vertex v);

#endif