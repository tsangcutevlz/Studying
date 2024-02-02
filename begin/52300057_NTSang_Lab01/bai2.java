public class bai2 {
    public static void main(String[] args) {
        int[][] matrix1 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        int[][] matrix2 = { { 9, 8, 7 }, { 6, 5, 4 }, { 3, 2, 1 } };
        int[][] matrix3 = { { 1, 2 }, { 4, 5 } };
        int[][] addMatrix = addMatrixs(matrix1, matrix2);
        int[][] multiplyMatrix = multiplyMatrixs(matrix1, matrix2);
        int detMatrix2x = detMatrix2x(matrix3);
        int detMatrix3x = detMatrix3x(matrix2);
        System.out.println("Matrix after add two matrixs: ");
        displayMatrix(addMatrix);
        System.out.println("Matrix after multiply two matrixs: ");
        displayMatrix(multiplyMatrix);
        System.out.println("Determinant of a 2x2 Matrix (matrix3): " + detMatrix2x);
        System.out.println("Determinant of a 3x3 Matrix (matrix2): " + detMatrix3x);

    }

    public static void displayMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static int[][] addMatrixs(int[][] matrix1, int[][] matrix2) {
        int rows = matrix1.length;
        int columns = matrix1[0].length;
        int[][] resultMatrix = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        return resultMatrix;
    }

    public static int[][] multiplyMatrixs(int[][] matrix1, int[][] matrix2) {
        int rows = matrix1.length;
        int columns = matrix1[0].length;
        int[][] resultMatrix = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                resultMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
            }
        }
        return resultMatrix;
    }
    public static int detMatrix2x(int[][] matrix1){
        return matrix1[0][0] * matrix1[1][1] - matrix1[0][1] * matrix1[1][0];
    }
    public static int detMatrix3x(int[][] matrix1){
        return matrix1[0][0] * matrix1[1][1] * matrix1[2][2] + matrix1[0][1] * matrix1[1][2] * matrix1[2][0] + matrix1[0][2] * matrix1[1][0] *matrix1[2][1]
        - matrix1[0][2] * matrix1[1][1] * matrix1[2][0] - matrix1[0][1] * matrix1[1][0] * matrix1[2][2] - matrix1[0][0] * matrix1[1][2] * matrix1[2][1];
    }
}
