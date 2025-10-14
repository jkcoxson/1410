#include <fstream>
#include <iostream>

#include "gtest.h"

#include "Sudoku.hpp"

TEST(Sudoku, NewEvil)
{
  std::ifstream puzzleIn("evil_new.txt");
  std::ifstream answerIn("evil_new.answer");
  Sudoku puzzle;
  Sudoku answer;

  puzzleIn >> puzzle;
  answerIn >> answer;

  puzzle.printGrid();

  EXPECT_EQ(true, puzzle.solve());

  puzzle.printGrid();
  answer.printGrid();
  

  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      EXPECT_EQ(puzzle.getValue(i, j), answer.getValue(i, j));
    }
  }
 
}
TEST(Sudoku, Easy)
{
  std::ifstream puzzleIn("easy.txt");
  std::ifstream answerIn("easy.answer");
  Sudoku puzzle;
  Sudoku answer;

  puzzleIn >> puzzle;
  answerIn >> answer;

  EXPECT_EQ(true, puzzle.solve());

//  puzzle.printGrid();
  

  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      EXPECT_EQ(puzzle.getValue(i, j), answer.getValue(i, j));
    }
  }
 
}


TEST(Sudoku, Impossible)
{
    std::ifstream puzzleIn("impossible.txt");
    std::ifstream answerIn("easy.answer");
    Sudoku puzzle;
    Sudoku answer;

    puzzleIn >> puzzle;
    answerIn >> answer;
   // bool value = puzzle.solve();
   // if (value) puzzle.printGrid();
    EXPECT_EQ(false, puzzle.solve());

   
}


TEST(Sudoku, Medium)
{
  std::ifstream puzzleIn("medium.txt");
  std::ifstream answerIn("medium.answer");
  Sudoku puzzle;
  Sudoku answer;

  puzzleIn >> puzzle;
  answerIn >> answer;

  EXPECT_EQ(true, puzzle.solve());

  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      EXPECT_EQ(puzzle.getValue(i, j), answer.getValue(i, j));
    }
  }
}

TEST(Sudoku, Hard)
{
  std::ifstream puzzleIn("hard.txt");
  std::ifstream answerIn("hard.answer");
  Sudoku puzzle;
  Sudoku answer;

  puzzleIn >> puzzle;
  answerIn >> answer;

  EXPECT_EQ(true, puzzle.solve());

  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      EXPECT_EQ(puzzle.getValue(i, j), answer.getValue(i, j));
    }
  }
}

TEST(Sudoku, F23)
{
  std::ifstream puzzleIn("f23.txt");
  std::ifstream answerIn("f23.answer");
  Sudoku puzzle;
  Sudoku answer;

  puzzleIn >> puzzle;
  answerIn >> answer;

  EXPECT_EQ(true, puzzle.solve());

  //puzzle.printGrid();



  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      EXPECT_EQ(puzzle.getValue(i, j), answer.getValue(i, j));
    }
  } 
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

