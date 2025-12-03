
// Construction Rules for RES
// Initially, RES is empty.
// Choose any starting index i in the array ARR.
// Choose a direction:
// left (move to i-1, i-2, …), or
// right (move to i+1, i+2, …)
// Traverse the array cyclically in the chosen direction:
// If you go past the last element, jump to the first.
// If you go before the first element, jump to the last.
// Continue until you have visited all N elements exactly once.
// At each step of the traversal, append the chosen ARR element to RES.
// (Thus, RES will also have size N.)

