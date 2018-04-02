//
// Created by edai on 20/03/18.
//

#include <Engine.hpp>

GraphicalCore* GraphicalCore::instance = nullptr;

void GraphicalCore::Init()
{
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
}

bool GraphicalCore::Run(int ac, char **av, Options *options)
{
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH) ;
    glutInitWindowPosition(0,0);
    glutInitWindowSize(options->width, options->height);
    glutCreateWindow(options->window_name.c_str());
    Init();
    glutIdleFunc(Engine::_Update);
    glutReshapeFunc(GraphicalCore::Reshape);
    glutSpecialFunc(GraphicalCore::_SpecialKeyHandle);
    glutKeyboardFunc(GraphicalCore::_KeyboardHandle);
    glutMainLoop();
    return (true);
}

void GraphicalCore::UpdateGl()
{
    glutSwapBuffers();
    glutPostRedisplay();
}

void GraphicalCore::KeyboardHandle(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            glutLeaveMainLoop();
            break;
        default:
            return;
    }
}

void GraphicalCore::SpecialKeyHandle(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void GraphicalCore::Reshape(int w, int h)
{
    auto wf = (GLfloat)w;
    auto hf = (GLfloat)h;

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5f, 1.5f, -1.5f * hf / wf,
                 1.5f * hf / wf, -10.0, 10.0);
    else
        glOrtho (-1.5f * wf / hf,
                 1.5f * wf / hf, -1.5f, 1.5f, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

GraphicalCore::GraphicalCore() = default;

GraphicalCore::~GraphicalCore() = default;