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

/// \file       LitTextureShader.hpp
/// \date       20/02/2018
/// \project    Cardinal Engine
/// \package    Runtime/Rendering/Shader/Built-in
/// \author     Vincent STEHLY--CALISTO

#ifndef CARDINAL_ENGINE_LIT_TEXTURE_SHADER_HPP__
#define CARDINAL_ENGINE_LIT_TEXTURE_SHADER_HPP__

#include "Runtime/Rendering/Shader/IShader.hpp"

/// \namespace cardinal
namespace cardinal
{

/// \class LitTextureShader
/// \brief Texture with ligthing
class LitTextureShader : public IShader
{
public:

    /// \brief Constructor
    LitTextureShader();

    /// \brief Sets the texture of the shader
    void SetTexture(uint textureID);

    /// \brief Sets up the pipeline for the shader
    /// \param MVP The Projection-View-Model matrix to pass to the shader
    void Begin(glm::mat4 const& MVP) final;

    /// \brief Restore the pipeline state
    void End() final;

private:

    uint m_textureID;
    int  m_textureSampler;
};

} // !namespace

#endif // !CARDINAL_ENGINE_LIT_TEXTURE_SHADER_HPP__