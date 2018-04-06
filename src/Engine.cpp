//
// Created by edai on 20/03/18.
//

#include "Engine.hpp"

Engine *Engine::instance = nullptr;

GLfloat Engine::bezier_points[4][4][3] = {
    {{ -1.5, -1.5, -0.5}, { -0.5, -1.5, -0.5}, {0.5, -1.5, -0.5}, {1.5, -1.5, -0.5}},
    {{ -1.5, -0.5, -0.5}, { -0.5, -0.5, -0.5}, {0.5, -0.5, -0.5}, {1.5, -0.5, -0.5}},
    {{ -1.5, 0.5, -0.5}, { -0.5, 0.5, -0.5}, {0.5, 0.5, -0.5}, {1.5, 0.5, -0.5}},
    {{ -1.5, 1.5, -0.5}, { -0.5, 1.5, -0.5}, {0.5, 1.5, -0.5}, {1.5, 1.5, -0.5}}
};

GLfloat texpts[2][2][2] = {{{0.0, 0. 0}, {0.0, 1.0}},
                           {{1.0, 0.0}, {1.0, 1.0}}};

Engine::~Engine() = default;

void Engine::InitTextures()
{
    textures = new std::vector<GLuint>();
    glEnable(GL_TEXTURE_2D);
}

Engine::Engine()
{
    InitTextures();
    glEnable(GL_MAP2_TEXTURE_COORD_2);
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_DEPTH_TEST);
    glShadeModel (GL_FLAT);
    glScalef(0.5f, 0.5f, 1.0f);
}

void Engine::InitUpdate()
{

}

void Engine::EndUpdate()
{
}

void Engine::Update()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
            0, 1, 12, 4, &bezier_points[0][0][0]);
    glMapGrid2f(4, 0.0, 1.0, 4, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glEvalMesh2(GL_LINE, 0, 20, 0, 20);
}