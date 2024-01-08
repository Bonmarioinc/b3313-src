#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"
#include "geo_commands_leek.h"
#include "make_const_nonconst.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-braces"
#define ShapeColor_newrabbit_base(r,g,b) {{r/4 ,g/4 ,b/4 ,0 ,r/4 ,g/4 ,b/4 ,0 },{ r,g,b,0, r,g,b,0, 40, 40, 40, 0} }

static Lights1 light_newrabbit_base[]={
	ShapeColor_newrabbit_base(255,160,173),
	ShapeColor_newrabbit_base(236,62,93),
	ShapeColor_newrabbit_base(127,127,127),
	ShapeColor_newrabbit_base(38,38,38),
	ShapeColor_newrabbit_base(20,20,20),
	ShapeColor_newrabbit_base(25,25,25),
};

static Vtx vtx_newrabbit_base[]={
	{72,14,33,0,0,0,15,-70,104,0},
	{-3,14,22,0,0,0,-15,-67,106,0},
	{-3,-20,0,0,0,0,-13,-70,105,0},
	{-3,-20,0,0,0,0,-13,-70,-105,0},
	{-3,14,-21,0,0,0,-15,-67,-106,0},
	{72,14,-32,0,0,0,15,-70,-104,0},
	{-3,-20,0,0,0,0,-13,-70,-105,0},
	{72,14,-32,0,0,0,15,-70,-104,0},
	{72,-33,0,0,0,0,31,-70,-100,0},
	{72,14,-32,0,0,0,15,-70,-104,0},
	{111,13,0,0,0,0,71,-60,-85,0},
	{72,-33,0,0,0,0,31,-70,-100,0},
	{-3,-20,0,0,0,0,-127,0,0,0},
	{-3,14,22,0,0,0,-127,0,0,0},
	{-3,14,-21,0,0,0,-127,0,0,0},
	{-3,-20,0,0,0,0,-13,-70,105,0},
	{72,-33,0,0,0,0,31,-70,100,0},
	{72,14,33,0,0,0,15,-70,104,0},
	{111,13,0,0,0,0,71,-60,85,0},
	{72,14,33,0,0,0,15,-70,104,0},
	{72,-33,0,0,0,0,31,-70,100,0},
	{-3,14,-21,0,0,0,0,127,0,0},
	{72,14,33,0,0,0,0,127,0,0},
	{72,14,-32,0,0,0,0,127,0,0},
	{-3,14,-21,0,0,0,0,127,0,0},
	{-3,14,22,0,0,0,0,127,0,0},
	{72,14,33,0,0,0,0,127,0,0},
	{72,14,33,0,0,0,0,127,0,0},
	{111,13,0,0,0,0,0,127,0,0},
	{72,14,-32,0,0,0,0,127,0,0},
	{78,14,23,0,0,0,-6,-75,101,0},
	{0,7,15,0,0,0,-3,-80,97,0},
	{1,-10,0,0,0,0,-6,-75,101,0},
	{1,-10,0,0,0,0,-6,-75,-101,0},
	{0,7,-13,0,0,0,-3,-80,-97,0},
	{78,14,-22,0,0,0,-6,-75,-101,0},
	{1,-10,0,0,0,0,-6,-75,-101,0},
	{78,14,-22,0,0,0,-6,-75,-101,0},
	{81,-21,0,0,0,0,-9,-69,-105,0},
	{1,-10,0,0,0,0,-126,-12,0,0},
	{0,7,15,0,0,0,-126,-12,0,0},
	{0,7,-13,0,0,0,-126,-12,0,0},
	{1,-10,0,0,0,0,-6,-75,101,0},
	{81,-21,0,0,0,0,-9,-69,105,0},
	{78,14,23,0,0,0,-6,-75,101,0},
	{78,14,23,0,0,0,126,12,0,0},
	{81,-21,0,0,0,0,126,12,0,0},
	{78,14,-22,0,0,0,126,12,0,0},
	{0,7,-13,0,0,0,-12,126,0,0},
	{0,7,15,0,0,0,-12,126,0,0},
	{78,14,23,0,0,0,-12,126,0,0},
	{0,7,-13,0,0,0,-12,126,0,0},
	{78,14,23,0,0,0,-12,126,0,0},
	{78,14,-22,0,0,0,-12,126,0,0},
	{72,14,32,0,0,0,0,127,0,0},
	{111,13,0,0,0,0,0,127,0,0},
	{72,14,-33,0,0,0,0,127,0,0},
	{72,14,32,0,0,0,0,127,0,0},
	{72,14,-33,0,0,0,0,127,0,0},
	{-3,14,21,0,0,0,0,127,0,0},
	{72,14,-33,0,0,0,0,127,0,0},
	{-3,14,-22,0,0,0,0,127,0,0},
	{-3,14,21,0,0,0,0,127,0,0},
	{-3,14,21,0,0,0,-127,0,0,0},
	{-3,14,-22,0,0,0,-127,0,0,0},
	{-3,-20,0,0,0,0,-127,0,0,0},
	{72,-33,0,0,0,0,31,-70,100,0},
	{111,13,0,0,0,0,71,-60,85,0},
	{72,14,32,0,0,0,15,-70,104,0},
	{72,-33,0,0,0,0,31,-70,100,0},
	{72,14,32,0,0,0,15,-70,104,0},
	{-3,-20,0,0,0,0,-13,-70,105,0},
	{72,-33,0,0,0,0,31,-70,-100,0},
	{72,14,-33,0,0,0,15,-70,-104,0},
	{111,13,0,0,0,0,71,-60,-85,0},
	{72,14,-33,0,0,0,15,-70,-104,0},
	{72,-33,0,0,0,0,31,-70,-100,0},
	{-3,-20,0,0,0,0,-13,-70,-105,0},
	{72,14,32,0,0,0,15,-70,104,0},
	{-3,14,21,0,0,0,-15,-67,106,0},
	{-3,-20,0,0,0,0,-13,-70,105,0},
	{-3,-20,0,0,0,0,-13,-70,-105,0},
	{-3,14,-22,0,0,0,-15,-67,-106,0},
	{72,14,-33,0,0,0,15,-70,-104,0},
	{78,14,22,0,0,0,126,12,0,0},
	{81,-21,0,0,0,0,126,12,0,0},
	{78,14,-23,0,0,0,126,12,0,0},
	{78,14,-23,0,0,0,-6,-75,-101,0},
	{81,-21,0,0,0,0,-9,-69,-105,0},
	{1,-10,0,0,0,0,-6,-75,-101,0},
	{0,7,13,0,0,0,-126,-12,0,0},
	{0,7,-15,0,0,0,-126,-12,0,0},
	{1,-10,0,0,0,0,-126,-12,0,0},
	{81,-21,0,0,0,0,-9,-69,105,0},
	{78,14,22,0,0,0,-6,-75,101,0},
	{1,-10,0,0,0,0,-6,-75,101,0},
	{78,14,22,0,0,0,-6,-75,101,0},
	{0,7,13,0,0,0,-3,-80,97,0},
	{1,-10,0,0,0,0,-6,-75,101,0},
	{1,-10,0,0,0,0,-6,-75,-101,0},
	{0,7,-15,0,0,0,-3,-80,-97,0},
	{78,14,-23,0,0,0,-6,-75,-101,0},
	{78,14,22,0,0,0,-12,126,0,0},
	{78,14,-23,0,0,0,-12,126,0,0},
	{0,7,13,0,0,0,-12,126,0,0},
	{78,14,-23,0,0,0,-12,126,0,0},
	{0,7,-15,0,0,0,-12,126,0,0},
	{0,7,13,0,0,0,-12,126,0,0},
	{-1,6,40,0,0,0,-127,-1,0,0},
	{-1,6,-40,0,0,0,-127,-1,0,0},
	{0,-32,25,0,0,0,-127,-1,0,0},
	{85,-37,33,0,0,0,43,-87,80,0},
	{85,9,53,0,0,0,49,-45,108,0},
	{-1,6,40,0,0,0,-14,-48,116,0},
	{-1,6,-40,0,0,0,-14,-48,-116,0},
	{85,9,-52,0,0,0,49,-45,-108,0},
	{85,-37,-33,0,0,0,34,-101,-67,0},
	{85,-37,-33,0,0,0,34,-101,-67,0},
	{85,-37,33,0,0,0,43,-87,80,0},
	{0,-32,25,0,0,0,-6,-126,0,0},
	{85,9,-52,0,0,0,49,-45,-108,0},
	{123,9,0,0,0,0,115,-53,0,0},
	{85,-37,-33,0,0,0,34,-101,-67,0},
	{123,9,0,0,0,0,115,-53,0,0},
	{85,9,53,0,0,0,49,-45,108,0},
	{85,-37,33,0,0,0,43,-87,80,0},
	{123,9,0,0,0,0,115,-53,0,0},
	{85,-37,33,0,0,0,43,-87,80,0},
	{85,-37,-33,0,0,0,34,-101,-67,0},
	{0,-32,25,0,0,0,-6,-126,0,0},
	{0,-32,-24,0,0,0,-6,-126,0,0},
	{85,-37,-33,0,0,0,34,-101,-67,0},
	{85,-37,-33,0,0,0,34,-101,-67,0},
	{0,-32,-24,0,0,0,-13,-46,-117,0},
	{-1,6,-40,0,0,0,-14,-48,-116,0},
	{-1,6,40,0,0,0,-14,-48,116,0},
	{0,-32,25,0,0,0,-13,-46,117,0},
	{85,-37,33,0,0,0,43,-87,80,0},
	{-1,6,-40,0,0,0,-127,-1,0,0},
	{0,-32,-24,0,0,0,-127,-1,0,0},
	{0,-32,25,0,0,0,-127,-1,0,0},
	{85,9,-52,0,0,0,-3,127,0,0},
	{-1,6,40,0,0,0,-4,126,0,0},
	{85,9,53,0,0,0,-2,127,0,0},
	{85,9,-52,0,0,0,-3,127,0,0},
	{-1,6,-40,0,0,0,-4,126,0,0},
	{-1,6,40,0,0,0,-4,126,0,0},
	{85,9,53,0,0,0,-2,127,0,0},
	{123,9,0,0,0,0,-1,127,0,0},
	{85,9,-52,0,0,0,-3,127,0,0},
	{-21,18,1,0,0,0,-102,-74,0,0},
	{27,-24,25,0,0,0,-75,-60,82,0},
	{-5,53,29,0,0,0,-56,-30,109,0},
	{-5,53,-26,0,0,0,-56,-30,-109,0},
	{51,3,-33,0,0,0,-32,-20,-121,0},
	{27,-24,-22,0,0,0,-75,-60,-82,0},
	{-21,18,1,0,0,0,-102,-74,0,0},
	{27,-24,-22,0,0,0,-75,-60,-82,0},
	{27,-24,25,0,0,0,-75,-60,82,0},
	{-5,53,-26,0,0,0,-116,51,0,0},
	{-21,18,1,0,0,0,-116,51,0,0},
	{-5,53,29,0,0,0,-116,51,0,0},
	{27,-24,-22,0,0,0,96,-83,0,0},
	{51,3,-33,0,0,0,96,-83,0,0},
	{51,3,36,0,0,0,96,-83,0,0},
	{51,3,36,0,0,0,96,-83,0,0},
	{27,-24,25,0,0,0,96,-83,0,0},
	{27,-24,-22,0,0,0,96,-83,0,0},
	{27,-24,25,0,0,0,-75,-60,82,0},
	{51,3,36,0,0,0,-32,-20,121,0},
	{-5,53,29,0,0,0,-56,-30,109,0},
	{27,-24,-22,0,0,0,-75,-60,-82,0},
	{-21,18,1,0,0,0,-102,-74,0,0},
	{-5,53,-26,0,0,0,-56,-30,-109,0},
	{-5,53,-26,0,0,0,83,96,0,0},
	{-5,53,29,0,0,0,83,96,0,0},
	{51,3,36,0,0,0,83,96,0,0},
	{51,3,36,0,0,0,83,96,0,0},
	{51,3,-33,0,0,0,83,96,0,0},
	{-5,53,-26,0,0,0,83,96,0,0},
	{50,22,0,0,0,0,-11,59,-111,0},
	{48,-15,-20,0,0,0,-10,58,-112,0},
	{-2,-10,-12,0,0,0,-11,59,-111,0},
	{48,-14,21,0,0,0,-10,64,108,0},
	{50,22,0,0,0,0,-12,66,107,0},
	{-2,-9,14,0,0,0,-12,66,107,0},
	{-1,12,0,0,0,0,-126,5,0,0},
	{-2,-10,-12,0,0,0,-126,5,0,0},
	{-2,-9,14,0,0,0,-126,5,0,0},
	{50,22,0,0,0,0,126,-5,0,0},
	{48,-14,21,0,0,0,126,-5,0,0},
	{48,-15,-20,0,0,0,126,-5,0,0},
	{48,-15,-20,0,0,0,-12,-126,4,0},
	{48,-14,21,0,0,0,-12,-126,4,0},
	{-2,-10,-12,0,0,0,-12,-126,4,0},
	{48,-14,21,0,0,0,-12,-126,4,0},
	{-2,-9,14,0,0,0,-12,-126,4,0},
	{-2,-10,-12,0,0,0,-12,-126,4,0},
	{50,22,0,0,0,0,-12,66,107,0},
	{-1,12,0,0,0,0,-13,68,106,0},
	{-2,-9,14,0,0,0,-12,66,107,0},
	{-2,-10,-12,0,0,0,-11,59,-111,0},
	{-1,12,0,0,0,0,-12,60,-110,0},
	{50,22,0,0,0,0,-11,59,-111,0},
	{85,-37,33,0,0,0,33,-102,67,0},
	{85,-37,-33,0,0,0,42,-88,-80,0},
	{123,8,0,0,0,0,114,-54,0,0},
	{85,-37,-33,0,0,0,42,-88,-80,0},
	{85,8,-53,0,0,0,48,-45,-108,0},
	{123,8,0,0,0,0,114,-54,0,0},
	{85,-37,33,0,0,0,33,-102,67,0},
	{123,8,0,0,0,0,114,-54,0,0},
	{85,8,52,0,0,0,48,-45,108,0},
	{-1,-32,-25,0,0,0,-8,-126,0,0},
	{85,-37,-33,0,0,0,42,-88,-80,0},
	{85,-37,33,0,0,0,33,-102,67,0},
	{85,-37,33,0,0,0,33,-102,67,0},
	{85,8,52,0,0,0,48,-45,108,0},
	{-1,6,40,0,0,0,-15,-47,116,0},
	{-1,6,-40,0,0,0,-15,-47,-116,0},
	{85,8,-53,0,0,0,48,-45,-108,0},
	{85,-37,-33,0,0,0,42,-88,-80,0},
	{-1,-32,-25,0,0,0,-127,0,0,0},
	{-1,6,40,0,0,0,-127,0,0,0},
	{-1,6,-40,0,0,0,-127,0,0,0},
	{-1,-32,-25,0,0,0,-127,0,0,0},
	{-1,-32,24,0,0,0,-127,0,0,0},
	{-1,6,40,0,0,0,-127,0,0,0},
	{85,-37,-33,0,0,0,42,-88,-80,0},
	{-1,-32,-25,0,0,0,-14,-46,-117,0},
	{-1,6,-40,0,0,0,-15,-47,-116,0},
	{-1,6,40,0,0,0,-15,-47,116,0},
	{-1,-32,24,0,0,0,-14,-46,117,0},
	{85,-37,33,0,0,0,33,-102,67,0},
	{85,-37,33,0,0,0,33,-102,67,0},
	{-1,-32,24,0,0,0,-8,-126,0,0},
	{-1,-32,-25,0,0,0,-8,-126,0,0},
	{85,8,52,0,0,0,-2,127,0,0},
	{123,8,0,0,0,0,0,127,0,0},
	{85,8,-53,0,0,0,-1,127,0,0},
	{85,8,-53,0,0,0,-1,127,0,0},
	{-1,6,-40,0,0,0,-3,127,0,0},
	{85,8,52,0,0,0,-2,127,0,0},
	{-1,6,-40,0,0,0,-3,127,0,0},
	{-1,6,40,0,0,0,-3,127,0,0},
	{85,8,52,0,0,0,-2,127,0,0},
	{51,3,-36,0,0,0,96,-83,0,0},
	{51,3,33,0,0,0,96,-83,0,0},
	{27,-24,23,0,0,0,96,-83,0,0},
	{-21,18,-1,0,0,0,-116,51,0,0},
	{-5,53,26,0,0,0,-116,51,0,0},
	{-5,53,-29,0,0,0,-116,51,0,0},
	{27,-24,-27,0,0,0,-75,-58,-83,0},
	{27,-24,23,0,0,0,-75,-58,83,0},
	{-21,18,-1,0,0,0,-103,-73,0,0},
	{-5,53,26,0,0,0,-56,-27,110,0},
	{-21,18,-1,0,0,0,-103,-73,0,0},
	{27,-24,23,0,0,0,-75,-58,83,0},
	{-5,53,-29,0,0,0,-56,-27,-110,0},
	{51,3,-36,0,0,0,-29,-16,-122,0},
	{27,-24,-27,0,0,0,-75,-58,-83,0},
	{27,-24,-27,0,0,0,-75,-58,-83,0},
	{-21,18,-1,0,0,0,-103,-73,0,0},
	{-5,53,-29,0,0,0,-56,-27,-110,0},
	{27,-24,23,0,0,0,-75,-58,83,0},
	{51,3,33,0,0,0,-29,-16,122,0},
	{-5,53,26,0,0,0,-56,-27,110,0},
	{27,-24,23,0,0,0,96,-83,0,0},
	{27,-24,-27,0,0,0,96,-83,0,0},
	{51,3,-36,0,0,0,96,-83,0,0},
	{51,3,-36,0,0,0,83,96,0,0},
	{-5,53,-29,0,0,0,83,96,0,0},
	{-5,53,26,0,0,0,83,96,0,0},
	{-5,53,26,0,0,0,83,96,0,0},
	{51,3,33,0,0,0,83,96,0,0},
	{51,3,-36,0,0,0,83,96,0,0},
	{-2,-10,14,0,0,0,-12,-126,0,0},
	{48,-15,-20,0,0,0,-12,-126,0,0},
	{48,-15,21,0,0,0,-12,-126,0,0},
	{48,-15,21,0,0,0,126,-5,0,0},
	{48,-15,-20,0,0,0,126,-5,0,0},
	{50,22,0,0,0,0,126,-5,0,0},
	{-2,-10,-12,0,0,0,-126,5,0,0},
	{-2,-10,14,0,0,0,-126,5,0,0},
	{-1,12,0,0,0,0,-126,5,0,0},
	{-2,-10,-12,0,0,0,-12,62,-109,0},
	{50,22,0,0,0,0,-12,62,-109,0},
	{48,-15,-20,0,0,0,-10,61,-110,0},
	{-2,-10,14,0,0,0,-12,63,109,0},
	{48,-15,21,0,0,0,-10,61,110,0},
	{50,22,0,0,0,0,-12,63,109,0},
	{50,22,0,0,0,0,-12,63,109,0},
	{-1,12,0,0,0,0,-13,64,108,0},
	{-2,-10,14,0,0,0,-12,63,109,0},
	{-2,-10,-12,0,0,0,-12,62,-109,0},
	{-1,12,0,0,0,0,-13,64,-108,0},
	{50,22,0,0,0,0,-12,62,-109,0},
	{-2,-10,14,0,0,0,-12,-126,0,0},
	{-2,-10,-12,0,0,0,-12,-126,0,0},
	{48,-15,-20,0,0,0,-12,-126,0,0},
	{7,63,-31,0,0,0,-59,82,-76,0},
	{29,81,0,0,0,0,2,127,0,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{10,-43,33,0,0,0,-64,-91,60,0},
	{48,-45,-37,0,0,0,43,-104,-58,0},
	{48,-45,37,0,0,0,52,-92,69,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{4,10,52,0,0,0,-91,0,87,0},
	{7,63,31,0,0,0,-59,82,75,0},
	{7,63,31,0,0,0,-59,82,75,0},
	{4,10,52,0,0,0,-91,0,87,0},
	{53,24,64,0,0,0,21,23,122,0},
	{10,-43,-33,0,0,0,-75,-73,-71,0},
	{53,24,-64,0,0,0,21,23,-122,0},
	{48,-45,-37,0,0,0,43,-104,-58,0},
	{29,81,0,0,0,0,2,127,0,0},
	{7,63,31,0,0,0,-59,82,75,0},
	{43,63,15,0,0,0,70,89,56,0},
	{4,10,-52,0,0,0,-91,0,-87,0},
	{7,63,-31,0,0,0,-59,82,-76,0},
	{53,24,-64,0,0,0,21,23,-122,0},
	{4,10,52,0,0,0,-91,0,87,0},
	{10,-43,33,0,0,0,-64,-91,60,0},
	{53,24,64,0,0,0,21,23,122,0},
	{97,20,26,0,0,0,110,40,48,0},
	{53,24,64,0,0,0,21,23,122,0},
	{48,-45,37,0,0,0,52,-92,69,0},
	{29,81,0,0,0,0,2,127,0,0},
	{7,63,-31,0,0,0,-59,82,-76,0},
	{-1,65,0,0,0,0,-104,72,0,0},
	{10,-43,33,0,0,0,-64,-91,60,0},
	{4,10,52,0,0,0,-91,0,87,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{48,-45,-37,0,0,0,43,-104,-58,0},
	{53,24,-64,0,0,0,21,23,-122,0},
	{97,20,-26,0,0,0,110,23,-57,0},
	{97,20,26,0,0,0,110,40,48,0},
	{48,-45,37,0,0,0,52,-92,69,0},
	{95,-17,0,0,0,0,109,-64,0,0},
	{43,63,15,0,0,0,70,89,56,0},
	{53,24,64,0,0,0,21,23,122,0},
	{97,20,26,0,0,0,110,40,48,0},
	{48,-45,37,0,0,0,52,-92,69,0},
	{48,-45,-37,0,0,0,43,-104,-58,0},
	{95,-17,0,0,0,0,109,-64,0,0},
	{48,-45,-37,0,0,0,43,-104,-58,0},
	{97,20,-26,0,0,0,110,23,-57,0},
	{95,-17,0,0,0,0,109,-64,0,0},
	{53,24,-64,0,0,0,21,23,-122,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{97,20,-26,0,0,0,110,23,-57,0},
	{53,24,64,0,0,0,21,23,122,0},
	{43,63,15,0,0,0,70,89,56,0},
	{7,63,31,0,0,0,-59,82,75,0},
	{7,63,-31,0,0,0,-59,82,-76,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{53,24,-64,0,0,0,21,23,-122,0},
	{-1,65,0,0,0,0,-104,72,0,0},
	{7,63,31,0,0,0,-59,82,75,0},
	{29,81,0,0,0,0,2,127,0,0},
	{7,63,-31,0,0,0,-59,82,-76,0},
	{4,10,-52,0,0,0,-91,0,-87,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{10,-43,33,0,0,0,-64,-91,60,0},
	{48,-45,37,0,0,0,52,-92,69,0},
	{53,24,64,0,0,0,21,23,122,0},
	{10,-43,-33,0,0,0,-75,-73,-71,0},
	{4,10,-52,0,0,0,-91,0,-87,0},
	{53,24,-64,0,0,0,21,23,-122,0},
	{97,20,26,0,0,0,110,40,48,0},
	{95,-17,0,0,0,0,109,-64,0,0},
	{97,20,-26,0,0,0,110,23,-57,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{97,20,26,0,0,0,110,40,48,0},
	{97,20,-26,0,0,0,110,23,-57,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{4,10,-52,0,0,0,-91,0,-87,0},
	{10,-43,-33,0,0,0,-75,-73,-71,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{10,-43,-33,0,0,0,-75,-73,-71,0},
	{10,-43,33,0,0,0,-64,-91,60,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{43,63,15,0,0,0,70,89,56,0},
	{97,20,26,0,0,0,110,40,48,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{-1,65,0,0,0,0,-104,72,0,0},
	{7,63,-31,0,0,0,-59,82,-76,0},
	{7,63,31,0,0,0,-59,82,75,0},
	{-1,65,0,0,0,0,-104,72,0,0},
	{-7,11,0,0,0,0,-127,-2,0,0},
	{10,-43,33,0,0,0,-64,-91,60,0},
	{10,-43,-33,0,0,0,-75,-73,-71,0},
	{48,-45,-37,0,0,0,43,-104,-58,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{45,76,0,0,0,0,93,86,0,0},
	{43,63,15,0,0,0,70,89,56,0},
	{45,76,0,0,0,0,93,86,0,0},
	{43,63,-15,0,0,0,73,91,-48,0},
	{29,81,0,0,0,0,2,127,0,0},
	{29,81,0,0,0,0,2,127,0,0},
	{43,63,15,0,0,0,70,89,56,0},
	{45,76,0,0,0,0,93,86,0,0},
	{-13,65,-22,0,0,0,-12,121,-36,0},
	{32,30,22,0,0,0,58,106,36,0},
	{32,29,-23,0,0,0,56,100,-52,0},
	{-22,-66,0,0,0,0,-6,-126,0,0},
	{-15,-32,-59,0,0,0,-24,-49,-114,0},
	{21,-34,-48,0,0,0,61,-68,-87,0},
	{71,19,-14,0,0,0,89,66,-60,0},
	{71,19,14,0,0,0,96,44,69,0},
	{69,-25,0,0,0,0,109,-64,0,0},
	{-48,-34,-17,0,0,0,-119,3,-42,0},
	{-43,32,21,0,0,0,-114,47,28,0},
	{-43,32,-21,0,0,0,-110,46,-42,0},
	{-15,31,55,0,0,0,-30,51,111,0},
	{-15,-32,59,0,0,0,-25,-49,114,0},
	{21,10,51,0,0,0,50,35,111,0},
	{-15,-32,-59,0,0,0,-24,-49,-114,0},
	{-15,31,-55,0,0,0,-30,52,-111,0},
	{21,11,-50,0,0,0,50,36,-110,0},
	{-15,-32,-59,0,0,0,-24,-49,-114,0},
	{-22,-66,0,0,0,0,-6,-126,0,0},
	{-48,-34,-17,0,0,0,-119,3,-42,0},
	{69,-25,0,0,0,0,109,-64,0,0},
	{43,-43,0,0,0,0,57,-113,0,0},
	{21,-34,-48,0,0,0,61,-68,-87,0},
	{21,-33,48,0,0,0,61,-69,86,0},
	{43,-43,0,0,0,0,57,-113,0,0},
	{69,-25,0,0,0,0,109,-64,0,0},
	{-22,-66,0,0,0,0,-6,-126,0,0},
	{-15,-32,59,0,0,0,-25,-49,114,0},
	{-48,-34,17,0,0,0,-117,19,44,0},
	{-15,31,55,0,0,0,-30,51,111,0},
	{-13,65,22,0,0,0,-13,114,52,0},
	{-43,32,21,0,0,0,-114,47,28,0},
	{71,19,14,0,0,0,96,44,69,0},
	{32,30,22,0,0,0,58,106,36,0},
	{21,10,51,0,0,0,50,35,111,0},
	{21,11,-50,0,0,0,50,36,-110,0},
	{32,29,-23,0,0,0,56,100,-52,0},
	{71,19,-14,0,0,0,89,66,-60,0},
	{-13,65,-22,0,0,0,-12,121,-36,0},
	{-15,31,-55,0,0,0,-30,52,-111,0},
	{-43,32,-21,0,0,0,-110,46,-42,0},
	{-15,31,55,0,0,0,-30,51,111,0},
	{-48,-34,17,0,0,0,-117,19,44,0},
	{-15,-32,59,0,0,0,-25,-49,114,0},
	{-15,-32,-59,0,0,0,-24,-49,-114,0},
	{-48,-34,-17,0,0,0,-119,3,-42,0},
	{-15,31,-55,0,0,0,-30,52,-111,0},
	{21,-33,48,0,0,0,61,-69,86,0},
	{71,19,14,0,0,0,96,44,69,0},
	{21,10,51,0,0,0,50,35,111,0},
	{71,19,-14,0,0,0,89,66,-60,0},
	{69,-25,0,0,0,0,109,-64,0,0},
	{21,-34,-48,0,0,0,61,-68,-87,0},
	{-15,-32,59,0,0,0,-25,-49,114,0},
	{-22,-66,0,0,0,0,-6,-126,0,0},
	{21,-33,48,0,0,0,61,-69,86,0},
	{-43,32,21,0,0,0,-114,47,28,0},
	{-13,65,22,0,0,0,-13,114,52,0},
	{-13,65,-22,0,0,0,-12,121,-36,0},
	{32,30,22,0,0,0,58,106,36,0},
	{-13,65,22,0,0,0,-13,114,52,0},
	{-15,31,55,0,0,0,-30,51,111,0},
	{71,19,-14,0,0,0,89,66,-60,0},
	{32,29,-23,0,0,0,56,100,-52,0},
	{32,30,22,0,0,0,58,106,36,0},
	{-15,31,-55,0,0,0,-30,52,-111,0},
	{-13,65,-22,0,0,0,-12,121,-36,0},
	{32,29,-23,0,0,0,56,100,-52,0},
	{21,-33,48,0,0,0,61,-69,86,0},
	{69,-25,0,0,0,0,109,-64,0,0},
	{71,19,14,0,0,0,96,44,69,0},
	{21,-34,-48,0,0,0,61,-68,-87,0},
	{21,11,-50,0,0,0,50,36,-110,0},
	{71,19,-14,0,0,0,89,66,-60,0},
	{-22,-66,0,0,0,0,79,-10,-98,0},
	{-39,-102,0,0,0,0,26,-74,-98,0},
	{-71,-60,-40,0,0,0,50,-46,-106,0},
	{-71,-60,-40,0,0,0,-108,66,0,0},
	{-71,-60,40,0,0,0,-114,54,0,0},
	{-48,-34,17,0,0,0,-117,19,44,0},
	{-71,-60,40,0,0,0,50,-46,106,0},
	{-39,-102,0,0,0,0,26,-74,98,0},
	{-22,-66,0,0,0,0,79,-10,98,0},
	{-39,-102,0,0,0,0,26,-74,-98,0},
	{-76,-91,0,0,0,0,-27,-96,-77,0},
	{-71,-60,-40,0,0,0,50,-46,-106,0},
	{-71,-60,-40,0,0,0,-108,66,0,0},
	{-76,-91,0,0,0,0,-125,19,0,0},
	{-71,-60,40,0,0,0,-114,54,0,0},
	{-71,-60,40,0,0,0,50,-46,106,0},
	{-76,-91,0,0,0,0,-27,-96,77,0},
	{-39,-102,0,0,0,0,26,-74,98,0},
	{-22,-66,0,0,0,0,79,-10,98,0},
	{-48,-34,17,0,0,0,81,13,96,0},
	{-71,-60,40,0,0,0,50,-46,106,0},
	{-48,-34,17,0,0,0,-117,19,44,0},
	{-48,-34,-17,0,0,0,-119,3,-42,0},
	{-71,-60,-40,0,0,0,-108,66,0,0},
	{-71,-60,-40,0,0,0,50,-46,-106,0},
	{-48,-34,-17,0,0,0,81,13,-96,0},
	{-22,-66,0,0,0,0,79,-10,-98,0},
	{32,29,-23,0,0,0,56,100,-52,0},
	{21,11,-50,0,0,0,50,36,-110,0},
	{-15,31,-55,0,0,0,-30,52,-111,0},
	{32,30,22,0,0,0,58,106,36,0},
	{71,19,14,0,0,0,96,44,69,0},
	{71,19,-14,0,0,0,89,66,-60,0},
	{-15,31,55,0,0,0,-30,51,111,0},
	{21,10,51,0,0,0,50,35,111,0},
	{32,30,22,0,0,0,58,106,36,0},
	{-13,65,-22,0,0,0,-12,121,-36,0},
	{-43,32,-21,0,0,0,-110,46,-42,0},
	{-43,32,21,0,0,0,-114,47,28,0},
	{-22,-66,0,0,0,0,-6,-126,0,0},
	{43,-43,0,0,0,0,57,-113,0,0},
	{21,-33,48,0,0,0,61,-69,86,0},
	{-48,-34,-17,0,0,0,-119,3,-42,0},
	{-43,32,-21,0,0,0,-110,46,-42,0},
	{-15,31,-55,0,0,0,-30,52,-111,0},
	{-15,31,55,0,0,0,-30,51,111,0},
	{-43,32,21,0,0,0,-114,47,28,0},
	{-48,-34,17,0,0,0,-117,19,44,0},
	{21,11,-50,0,0,0,50,36,-110,0},
	{21,-34,-48,0,0,0,61,-68,-87,0},
	{-15,-32,-59,0,0,0,-24,-49,-114,0},
	{-15,-32,59,0,0,0,-25,-49,114,0},
	{21,-33,48,0,0,0,61,-69,86,0},
	{21,10,51,0,0,0,50,35,111,0},
	{-48,-34,-17,0,0,0,-119,3,-42,0},
	{-48,-34,17,0,0,0,-117,19,44,0},
	{-43,32,21,0,0,0,-114,47,28,0},
	{21,-34,-48,0,0,0,61,-68,-87,0},
	{43,-43,0,0,0,0,57,-113,0,0},
	{-22,-66,0,0,0,0,-6,-126,0,0},
	{-13,65,-22,0,0,0,-12,121,-36,0},
	{-13,65,22,0,0,0,-13,114,52,0},
	{32,30,22,0,0,0,58,106,36,0},
};

const Gfx RCP_newrabbit_base0[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[0],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[15],6,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[21],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base1[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[30],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[45],3,0),
	gsSP1Triangle(0,1,2,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[48],6,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base2[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[54],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[63],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[78],6,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base3[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[84],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[99],3,0),
	gsSP1Triangle(0,1,2,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[102],6,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base4[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[108],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[123],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[138],3,0),
	gsSP1Triangle(0,1,2,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[141],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base5[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[150],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[165],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[174],6,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base6[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[4].l[0]),1),
	gsSPLight((&light_newrabbit_base[4].a),2),
	gsSPVertex(&vtx_newrabbit_base[180],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[195],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base7[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[204],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[219],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[234],3,0),
	gsSP1Triangle(0,1,2,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[237],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base8[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[246],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[261],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPLight((&light_newrabbit_base[1].l[0]),1),
	gsSPLight((&light_newrabbit_base[1].a),2),
	gsSPVertex(&vtx_newrabbit_base[270],6,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base9[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[4].l[0]),1),
	gsSPLight((&light_newrabbit_base[4].a),2),
	gsSPVertex(&vtx_newrabbit_base[276],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[291],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base10[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[300],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[315],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[330],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[345],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[360],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[375],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[390],3,0),
	gsSP1Triangle(0,1,2,0),
	gsSPLight((&light_newrabbit_base[5].l[0]),1),
	gsSPLight((&light_newrabbit_base[5].a),2),
	gsSPVertex(&vtx_newrabbit_base[393],9,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSPEndDisplayList()
};
const Gfx RCP_newrabbit_base11[]={
	gsSPNumLights(NUMLIGHTS_1),
	gsSPLight((&light_newrabbit_base[0].l[0]),1),
	gsSPLight((&light_newrabbit_base[0].a),2),
	gsSPVertex(&vtx_newrabbit_base[402],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[417],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[432],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[447],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[462],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[477],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[492],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[507],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[522],15,0),
	gsSP1Triangle(0,1,2,0),
	gsSP1Triangle(3,4,5,0),
	gsSP1Triangle(6,7,8,0),
	gsSP1Triangle(9,10,11,0),
	gsSP1Triangle(12,13,14,0),
	gsSPVertex(&vtx_newrabbit_base[537],3,0),
	gsSP1Triangle(0,1,2,0),
	gsSPEndDisplayList()
};
#pragma GCC diagnostic pop
