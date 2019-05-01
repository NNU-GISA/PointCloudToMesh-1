#include "rply.h"
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>


using namespace std;
// use this namespace in this way:
// if (Surface::loadFile(filename)){//code}
namespace Surface
{
	struct vertex
	{
		float x;
		float y;
		float z;
	};

	vector<vertex> vertices;
    
	//temp data to perform the algorithm
	vertex tempVertex;
	int iIndex = 0;
	
	//vertex callback
	static int vertex_cb(p_ply_argument argument) {
		long eol;
		ply_get_argument_user_data(argument, NULL, &eol);
		switch (iIndex)
		{
		case 0:
			Surface::tempVertex.x = ply_get_argument_value(argument);
			iIndex++;
			break;
		case 1:
			Surface::tempVertex.y = ply_get_argument_value(argument);
			iIndex++;
			break;
		case 2:
			Surface::tempVertex.z = ply_get_argument_value(argument);
			Surface::vertices.push_back(Surface::tempVertex);
			iIndex = 0;
			break;
		}
		return 1;
	}

	//just call this function
	bool loadFile(string filename)
	{
		long nvertices;
		p_ply ply = ply_open(filename.c_str(), NULL, 0, NULL);
		if (!ply) return false;
		if (!ply_read_header(ply)) return false;
		nvertices = ply_set_read_cb(ply, "vertex", "x", vertex_cb, NULL, 0);
		ply_set_read_cb(ply, "vertex", "y", vertex_cb, NULL, 0);
		ply_set_read_cb(ply, "vertex", "z", vertex_cb, NULL, 1);
		//printf("%ld\n%ld\n", nvertices, ntriangles);
		if (!ply_read(ply)) return false;
		ply_close(ply);
		return true;
	}
}


int main(int argc, char** argv)
{
	if (!Surface::loadFile(".ply"))
		cout << "not loaded" << endl;
	else
	{
		for each (Surface::vertex v in Surface::vertices)
		{
			cout << v.x << " " << v.y << " " << v.z << endl;
		}
		
		cout << "nvertex: " << Surface::vertex.size() << endl;
	}
	return EXIT_SUCCESS;
}
