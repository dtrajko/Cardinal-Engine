#include <algorithm>
#include <random>
#include <numeric>

#include "World/Generator/Noise/PerlinNoise.hpp"

// Initialize with the reference values for the permutation vector
PerlinNoise::PerlinNoise(double p_amplitude, double p_shift) :
    m_amplitude(p_amplitude),
    m_shift(p_shift)
{
    // Initialize the permutation vector with the reference values
    m_permutation = {
        151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,
        8,99,37,240,21,10,23,190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,
        35,11,32,57,177,33,88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,
        134,139,48,27,166,77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,
        55,46,245,40,244,102,143,54, 65,25,63,161,1,216,80,73,209,76,132,187,208, 89,
        18,169,200,196,135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,
        250,124,123,5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,
        189,28,42,223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167,
        43,172,9,129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,
        97,228,251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,
        107,49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
        138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180 };
    // Duplicate the permutation vector
    m_permutation.insert(m_permutation.end(), m_permutation.begin(), m_permutation.end());
}

PerlinNoise::PerlinNoise(size_t p_seed, double p_amplitude, double p_shift):
    m_amplitude(p_amplitude),
    m_shift(p_shift)
{
    m_permutation.resize(256);

    // Fills of 0 to 255
    std::iota(m_permutation.begin(), m_permutation.end(), 0);

    // Prepare random shuffle
    std::default_random_engine engine(p_seed);

    // shuffle
    std::shuffle(m_permutation.begin(), m_permutation.end(), engine);

    // duplicate permutation vector
    m_permutation.insert(m_permutation.end(), m_permutation.begin(), m_permutation.end());
}

double PerlinNoise::noise(double x, double y, double z)
{
    // Find the unit cube that contains the point
    int X = (int)floor(x) & 255;
    int Y = (int)floor(y) & 255;
    int Z = (int)floor(z) & 255;

    // Find relative x,y,z of point in cube
    x -= floor(x);
    y -= floor(y);
    z -= floor(z);

    // Compute fade curves for each of x,y,z
    double u = fade(x);
    double v = fade(y);
    double w = fade(z);

    // Hash coordinates of the 8 cube corners
    int a = m_permutation[X] + Y;
    int aa = m_permutation[a] + Z;
    int ab = m_permutation[a+1] + Z;
    int b = m_permutation[X+1] + Y;
    int ba = m_permutation[b] + Z;
    int bb = m_permutation[b+1] + Z;

    // Add blended results from 8 corners of cube
    double res = lerp(
    w, 
    lerp(   v, 
            lerp(u, grad(m_permutation[aa], x, y, z),grad(m_permutation[ba], x - 1, y, z)),
            lerp(u, grad(m_permutation[ab], x, y - 1, z), grad(m_permutation[bb], x - 1, y - 1, z))
        ),
    lerp(   v, 
            lerp(u, grad(m_permutation[aa + 1], x, y, z - 1), grad(m_permutation[ba + 1], x - 1, y, z - 1)),
            lerp(u, grad(m_permutation[ab + 1], x, y - 1, z - 1), grad(m_permutation[bb + 1], x - 1, y - 1, z - 1)))
            );

    return (res + 1.0) * 0.5;
}

double PerlinNoise::fade(double t)
{
    return std::pow(t,3) * (t * (t * m_amplitude - m_shift) + 10);
}

double PerlinNoise::lerp(double t, double a, double b) 
{
    return a + t * (b - a);
}

double PerlinNoise::grad(int hash, double x, double y, double z) 
{
    int h = hash & 15;

    // Convert lower 4 bits of hash into 12 gradient directions
    double  u = h < 8 ? x : y,
            v = h < 4 ? y : h == 12 || h == 14 ? x : z;
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

double PerlinNoise::octave(double x, double y, double z, int octaves, double persistence) 
{
    double total = 0;
    double frequency = 1;
    double amplitude = 1;
    double maxValue = 0;  // Used for normalizing result to 0.0 - 1.0
    for (int i = 0;i<octaves;i++) {
        total += noise(x * frequency, y * frequency, z * frequency) * amplitude;

        maxValue += amplitude;

        amplitude *= persistence;
        frequency *= 2;
    }

    return total / maxValue;
}
