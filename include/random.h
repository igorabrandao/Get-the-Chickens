/*! \brief Class random.h.
 *
 *  Handle the random issues.
*/
#ifndef RANDOM_H
#define RANDOM_H

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>
 
using namespace std;

int generateRandom(int max);
int generateRandom0(int max);
bool generateRandomBool();

#endif // RANDOM_H