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

/// \file       TerrainRenderer.hpp
/// \date       14/02/2018
/// \project    Cardinal Engine
/// \package    World/Chunk/Renderer
/// \author     Vincent STEHLY--CALISTO

#ifndef CARDINAL_ENGINE_TERRAIN_RENDERER_HPP__
#define CARDINAL_ENGINE_TERRAIN_RENDERER_HPP__

#include <chrono>
#include <iostream>

#include "World/WorldBuffers.hpp"
#include "World/Cube/ByteCube.hpp"

#include "Runtime/Rendering/Renderer/MeshRenderer.hpp"

/// \class TerrainRenderer
/// \brief Renders all terrain blocks (not details, monsters etc.)
class TerrainRenderer
{
public:

    /// \brief Static batching for terrain cubes
    /// \param pCubes The cubes of the chunk
    void Batch(ByteCube pCubes[WorldSettings::s_chunkSize][WorldSettings::s_chunkSize][WorldSettings::s_chunkSize]);

    /// \brief Returns the mesh renderer
    cardinal::MeshRenderer * GetMeshRenderer();

    /// \brief Translate the chunk terrain renderer
    void Translate(glm::vec3 const& translation);

private:

    glm::vec3              m_model;
    cardinal::MeshRenderer m_renderer;
};

#endif // !CARDINAL_ENGINE_TERRAIN_RENDERER_HPP__