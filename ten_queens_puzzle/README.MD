This project is from C05.

Its purpose was to introduce resursion with an algorithmic principle.

This code relies on an algorithm called "backtracking".

The concept of the puzzle is to put all the queens all in each position in which none can attack the other in a single move.

So, instead of generating the full combination first then checking if positions are valid, the code checks if the position is safe from the previous posed queens before putting the new queen and moving to the next col, if not then it tries the next position in the the row; If neither of the places in the row are safe,it returns to the queen in the previous col and move it to the next safe row. if neither are found it returns to the previous col...etc; The application determines the board is valid when a queen is placed in the last col. the application terminates when the queen in first col is in the last position and the app tries to move it forward. indicating that no more positions are possible. 

The application time complexity is O(n2) since the app still iterates through all possible valid and invalid combinations, whereas n is the size of the nXn board and also the number of queens.

I kept the main function for testing purposes. if you want to try the application with diffrent board sizes you can use the flag ```-DSIZE=10``` and change the number.

the last line in the output is the number of solutions found.
