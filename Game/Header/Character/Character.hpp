/// Copyright (C) 2018-2019, Cardinal Engine
/// Vincent STEHLY--CALISTO, vincentstehly@hotmail.fr
///
/// This program is free software; you can redistribute it and/or modify
/// it under the terms of the GNU General Public License as published by
/// the Free Software Foundation; either version 2 of the License, or
/// (at your option) any later version.
///
/// This program is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
/// GNU General Public License for more details.
///
/// You should have received a copy of the GNU General Public License along
/// with this program; if not, write to the Free Software Foundation, Inc.,
/// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

/// \file       Character.hpp
/// \date       16/02/2018
/// \project    Cardinal Engine
/// \package    Character
/// \author     Vincent STEHLY--CALISTO

#ifndef CARDINAL_ENGINE_CHARACTER_HPP__
#define CARDINAL_ENGINE_CHARACTER_HPP__

/// Forward declaration
namespace cardinal
{
    class Window;
    class Camera;
}

#include "Glm/glm/glm.hpp"
#include "Runtime/Rendering/Renderer/TextRenderer.hpp"
#include "Runtime/Rendering/Renderer/MeshRenderer.hpp"
#include "Runtime/Physics/RigidBody.hpp"

/// \class Character
/// \brief 
class Character
{
public:

    /// \brief Constructor
    Character();

    /// \brief Updates the character
    /// \param pWindow The context
    /// \param dt The elapsed time
    void Update(cardinal::Window * pWindow, float dt);

    /// \brief Returns the position of the avatar
    glm::vec3 GetPosition() const;

    /// \brief Sets the position of the avatar
    void SetPosition(glm::vec3 position);

    /// \brief Gives main camera to character
    void AttachCamera(const cardinal::Camera* camera);

    /// \brief Translate the avatar
    /// \param translation The translation vector
    void Translate(glm::vec3 const& translation);

private:

    /// \brief Initializes the avatar mesh
    void InitializeAvatar();

private:
    // Controls
    glm::tvec3<double>      m_lastMouse;

    float                   m_speed             = 500.0f;
    float                   m_speedMultiplier   = 2.0f;
    float                   m_jumpImpulse       = 10;

    // Physics
    cardinal::RigidBody   * m_pBody;
    cardinal::MeshRenderer* m_meshRenderer;

    const cardinal::Camera* m_pCamera;
};

#endif // !CARDINAL_ENGINE_CHARACTER_HPP__