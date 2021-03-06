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

/// \file       LightStructure.hpp
/// \date       24/02/2018
/// \project    Cardinal Engine
/// \package    Runtime/Rendering/Lighting
/// \author     Vincent STEHLY--CALISTO

#ifndef CARDINAL_ENGINE_LIGHT_STRUCTURE_HPP__
#define CARDINAL_ENGINE_LIGHT_STRUCTURE_HPP__

#include "Glm/glm/vec3.hpp"

/// \namespace cardinal
namespace cardinal
{

/// \brief  Contains point light data
struct PointLightStructure
{
    float     range;
    float     intensity;
    glm::vec3 color;
    glm::vec3 position;
};

} // !namespace

#endif // !CARDINAL_ENGINE_LIGHT_STRUCTURE_HPP__