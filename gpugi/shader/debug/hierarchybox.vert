#version 450 core

#include "../stdheader.glsl"

layout(location = 0) in vec3 inPosition;
layout(location = 1) in int inBoxInstance;
layout(location = 2) in int inDepth;


layout(location = 0) out vec3 BoxPosition;
layout(location = 1) out int Depth;

void main()
{	
	const vec3 maxs[2] = { vec3(1, 1, 1), vec3(3, 3, 3) };
	const vec3 mins[2] = { vec3(0, 0, 0), vec3(2, 2, 2) };

	vec4 node0 = texelFetch(HierachyBuffer, int(inBoxInstance * 2));
	vec4 node1 = texelFetch(HierachyBuffer, int(inBoxInstance * 2 + 1));

	vec3 worldPosition;
	worldPosition.x = mix(node0.x, node1.x, inPosition.x);
	worldPosition.y = mix(node0.y, node1.y, inPosition.y);
	worldPosition.z = mix(node0.z, node1.z, inPosition.z);

	gl_Position = vec4(worldPosition, 1.0) * ViewProjection;
	BoxPosition = inPosition;
	Depth = inDepth;
}