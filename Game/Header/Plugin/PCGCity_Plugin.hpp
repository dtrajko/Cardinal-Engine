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

/// \file       PCGCity_Plugin.hpp
/// \date       06/03/2018
/// \project    Cardinal Engine
/// \package    Plugin
/// \author     Vincent STEHLY--CALISTO

#ifndef CARDINAL_ENGINE_PCG_CITY_PLUGIN_HPP__
#define CARDINAL_ENGINE_PCG_CITY_PLUGIN_HPP__

// Engine
#include "Runtime/Engine.hpp"

// Game
#include "World/World.hpp"
#include "Character/Character.hpp"
#include "City/ProceduralBuilding.hpp"
#include "Rendering/CameraManager.hpp"
#include "World/Generator/GUI/GeneratorGUI.hpp"

/// \brief Plugin for procedural city generation
/// \class PCGCity_Plugin
class PCGCity_Plugin : public cardinal::Plugin
{
public:

    static PCGCity_Plugin * s_pPlugin;

public:

    /// \brief Constructor
    PCGCity_Plugin();

    /// \brief Called when the game begins
    void OnPlayStart() final;

    /// \brief Called when the game stops
    void OnPlayStop () final;

    /// \brief Called just before the engine update
    void OnPreUpdate() final;

    /// \brief Called after the engine update
    /// \param dt The elapsed time in seconds
    void OnPostUpdate(float dt) final;

    /// \brief Called when it's time to render the GUI
    void OnGUI() final;

private:

    Character     m_character;
    CameraManager m_cameraManager;

    ProceduralBuilding m_building;
};

#endif // !CARDINAL_ENGINE_PCG_CITY_PLUGIN_HPP__

