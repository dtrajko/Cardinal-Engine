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

/// \file       Sharpen.cpp
/// \date       04/03/2018
/// \project    Cardinal Engine
/// \package    Runtime/Rendering/PostProcessing/PostEffects
/// \author     Vincent STEHLY--CALISTO

#include "Glew/include/GL/glew.h"
#include "Runtime/Rendering/Shader/ShaderManager.hpp"
#include "Runtime/Rendering/PostProcessing/PostEffects/Sharpen.hpp"

/// \namespace cardinal
namespace cardinal
{

/// \brief Constructor
Sharpen::Sharpen() : PostEffect(PostEffect::EType::Sharpen, "Sharpen")
{
    // Getting shader ...
    m_shaderID = (uint)ShaderManager::GetShaderID("SharpenPostProcess");

    // Getting uniforms
    m_weightID       = glGetUniformLocation(m_shaderID, "weight");
    m_colorTextureID = glGetUniformLocation(m_shaderID, "colorTexture");

    m_weight = 3;

    glUseProgram(m_shaderID);
    glUniform1i (m_weightID, m_weight);
    glUseProgram(0);
}

/// \brief Destructor
Sharpen::~Sharpen() // NOLINT
{
    // None
}

/// \brief Applies the effect from the given textures
/// \param colorTexture The color texture
/// \param depthTexture The depth buffer texture
/// \param lightScatteringTexture The result of the light scattering pass
void Sharpen::ApplyEffect(uint colorTexture, uint depthTexture, uint lightScatteringTexture,
                          uint shadowMapTexture)
{
    glUseProgram   (m_shaderID);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture  (GL_TEXTURE_2D, colorTexture);
    glUniform1i    (m_colorTextureID, 0);
}

/// \brief Called to draw the gui
void Sharpen::OnGUI()
{
    ImGui::Checkbox("Enabled###Enabled_Sharpen", &m_bIsActive);

    ImGui::Text("\nWeight");
    if(ImGui::SliderInt("###Slider_SharpenWeight", &m_weight, 3, 10))
    {
        glUseProgram(m_shaderID);
        glUniform1i (m_weightID, m_weight);
        glUseProgram(0);
    }
}

} // !namespace