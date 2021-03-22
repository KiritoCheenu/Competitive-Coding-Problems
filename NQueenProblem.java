public class NQueenProblem {
	final int N = 4;

	void printSolution(int chessBoard[][]) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				System.out.print(" " + chessBoard[i][j] + " ");
			System.out.println();
		}
	}

	boolean isSafe(int chessBoard[][], int row, int col) {
		int i, j;
		for (i = 0; i < col; i++)
			if (chessBoard[row][i] == 1)
				return false;
		for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
			if (chessBoard[i][j] == 1)
				return false;
		for (i = row, j = col; j >= 0 && i < N; i++, j--)
			if (chessBoard[i][j] == 1)
				return false;
		return true;
	}

	boolean solveNQUtil(int chessBoard[][], int col) {
		if (col >= N)
			return true;
		for (int i = 0; i < N; i++) {
			if (isSafe(chessBoard, i, col)) {
				chessBoard[i][col] = 1;
				if (solveNQUtil(chessBoard, col + 1) == true)
					return true;
				chessBoard[i][col] = 0;
			}
		}
		return false;
	}

	boolean solveNQ() {
		int chessBoard[][] = new int[N][N];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				chessBoard[i][j] = 0;
		if (solveNQUtil(chessBoard, 0) == false) {
			System.out.print("Solution does not exist");
			return false;
		}
		printSolution(chessBoard);
		return true;
	}

	public static void main(String args[]) {
		NQueenProblem Queen = new NQueenProblem();
		Queen.solveNQ();
	}
}
