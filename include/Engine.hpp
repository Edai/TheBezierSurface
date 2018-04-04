//
// Created by edai on 20/03/18.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "GraphicalCore.hpp"
#include <glm/glm.hpp>
#include <list>
#include <array>
#include <vector>

class Engine
{
public:
    Engine();
    ~Engine();

    static void _Update()
    {
        Instance()->InitUpdate();
        Instance()->Update();
        Instance()->EndUpdate();
        GraphicalCore::UpdateGl();
    }

    static GLfloat bezier_points[4][4][3];
    std::vector<GLuint> *textures;

private:
    void InitUpdate();
    void EndUpdate();
    void Update();
    void InitTextures();

#pragma SINGLETON
private:
    static Engine* instance;

public:
    static Engine* Instance()
    {
        if (instance == nullptr)
        {
            instance = new Engine();
        }
        return instance;
    }

#pragma END SINGLETON
};


#endif //ENGINE_HPP
