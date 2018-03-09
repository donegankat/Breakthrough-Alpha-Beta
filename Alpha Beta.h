/*
 *  Alpha Beta.h
 *  Breakthrough Alpha Beta
 *
 *  Created by K Donegan on 2/10/13.
 *  Copyright 2013 University of Denver. All rights reserved.
 *
 */

#ifndef ALPHA BETA_H
#define ALPHA BETA_H


#include "Game.h"
#include "Eval.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector



//static int alpha; //Minimum
//static int beta; //Maximum
//static int depth = 0;
//const int maxDepth = 5;


void AlphaBeta(BoardState s, int d);
void AlphaBeta1(BoardState s, int d);
void AlphaBeta2(BoardState s, int d);

static int GetNodesSearchedLast();
bool P1Win(BoardState s);
bool P2Win(BoardState s);
bool GameOver(BoardState s);
int GetOppositePlayer(int player);
static BoardState CopyBoard(BoardState s, int player);
static int ModifyDepth(int d, int PossibleMoves);
std::vector<BoardState> SortBoards(std::vector<BoardState> MyBoards);
static std::vector<BoardState> PossibleBoards(BoardState s, int player);
static BoardState FixedDepthAlphaBeta(BoardState ExamineBoard, int MaxDepth, int playerTurn);
static BoardState AlphaBetaTTRoot(BoardState ExamineBoard, int Depth, int playerTurn);
static int AlphaBetaTT(BoardState ExamineBoard, int Depth, int Alpha, int Beta, int playerTurn);

bool updateHistory(std::vector<PieceAction> &history, PieceAction newmove);
void Run(BoardState &s, int turn, int depth, int a, int b);
void playMoves(BoardState &s);

void DoMove(BoardState s);

void test(std::vector<PieceAction> x, BoardState s);

enum TTEntryType
{
	ExactValue, LowerBound, UpperBound
};

struct TTEntry
{
	int Value;
	TTEntryType Type;
	int Depth;
	
	TTEntry()
	{
		
	}
	
	TTEntry(int BoardValue, TTEntryType EntryType, int SearchDepth)
	{
		Value = BoardValue;
		Type = EntryType;
		Depth = SearchDepth;
	}
};



#endif