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

/// \file       Grass.hpp
/// \date       14/02/2018
/// \project    Cardinal Engine
/// \package    World/Detail
/// \author     Vincent STEHLY--CALISTO

#ifndef CARDINAL_ENGINE_GRASS_HPP__
#define CARDINAL_ENGINE_GRASS_HPP__

#include "Glm/glm/glm.hpp"

/// \class Grass
/// \brief Stores grass information
class Grass
{
public:

    /// \brief Stores grass vertices
    static const float s_vertices[36];

    /// \brief Returns the center position of the triangles
    inline glm::vec3 GetCenter();

    /// \brief Comparison method for std::sort
    inline bool operator< (const Grass& right) const;

    glm::vec2 uv[3];
    glm::vec3 vertex[3];
    float     squareDistance;
};

#include "World/Detail/Impl/Grass.inl"

#endif // !CARDINAL_ENGINE_GRASS_HPP__