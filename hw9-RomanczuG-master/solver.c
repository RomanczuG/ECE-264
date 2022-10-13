#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "solver.h"
#include "path.h"
#include "mazehelper.h"
char * solveMaze(Maze * m) {
    //An obvious upper bound on the size of the solution path is the number
    //of squares in the maze + 1 (to account for the '\0'). You could make
    //this a tighter bound by accounting for how many walls there are, but
    //this approach is good enough!
	char * retval = malloc(sizeof(char) * ((m->width * m->height) + 1));

	MazePos mp = {.xpos = m->start.xpos, .ypos = m->start.ypos};
	if (!depthFirstSolve(m, mp, retval, 0)) {
		fprintf(stderr, "No solution found!\n");
	} else {
		printf("Solution found: %s\n", retval);
	}
	
	return retval;
}

bool depthFirstSolve(Maze * m, MazePos curpos, char * path, int step) {
	
	if(squareOK(curpos,m))
	{
		if(atEnd(curpos, m))
		{
			path[step] = '\0';
			return true;
		}
		m->maze[curpos.ypos][curpos.xpos].visited = true;
		MazePos newPos = {.xpos = curpos.xpos, .ypos = curpos.ypos};
		newPos.xpos = curpos.xpos;
		newPos.ypos = curpos.ypos - 1;
		path[step] = 'n';
		if(depthFirstSolve(m,newPos,path,step + 1))
		{
			return true;
		}
		newPos.xpos = curpos.xpos;
		newPos.ypos = curpos.ypos + 1;
		path[step] = 's';
		if(depthFirstSolve(m,newPos,path,step + 1))
		{
			return true;
		}
		newPos.xpos = curpos.xpos+1;
		newPos.ypos = curpos.ypos;
		path[step] = 'e';
		if(depthFirstSolve(m,newPos,path,step + 1))
		{
			return true;
		}
		newPos.xpos = curpos.xpos - 1;
		newPos.ypos = curpos.ypos;
		path[step] = 'w';
		if(depthFirstSolve(m,newPos,path,step + 1))
		{
			return true;
		}
		return false;
	}
	else
	{
		return false;
	}
	

	//FILL IN

	return false;
}
