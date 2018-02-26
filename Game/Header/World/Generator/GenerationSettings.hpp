#pragma once

#include "World/Generator/Noise/FastNoise.h"

struct GenerationSettings
{
    // General settings
    FastNoise::NoiseType noiseType = FastNoise::NoiseType::PerlinFractal;
    int seed = 0;
    float frequency = 1;
    FastNoise::Interp interpolation = FastNoise::Interp::Hermite;

    // Fractal settings
    FastNoise::FractalType fractalType = FastNoise::FractalType::Billow;
    int octaves = 1;
    float gain = 1; // persistence

    // Cellular settings
    FastNoise::CellularDistanceFunction distanceFunction = FastNoise::CellularDistanceFunction::Euclidean;
    FastNoise::CellularReturnType returnType = FastNoise::CellularReturnType::CellValue;
};
