public class Main {
    public static void main(String[] args) {
        NNUEVisualization.init("nn-b1a57edbea57.nnue", "nn-baff1ede1f90.nnue");
        int[][] arr = NNUEVisualization.getNeurons("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

        System.out.print("fc_0: ");
        for (int i = 0; i < 32; i++) {
            System.out.print(arr[0][i] + " ");
        }
        System.out.println();

        // Print ac_sqr_0
        System.out.print("ac_sqr_0: ");
        for (int i = 0; i < 32; i++) {
            System.out.print(arr[1][i] + " ");
        }
        System.out.println();

        // Print ac_0
        System.out.print("ac_0: ");
        for (int i = 0; i < 32; i++) {
            System.out.print(arr[2][i] + " ");
        }
        System.out.println();

        // Print fc_1
        System.out.print("fc_1: ");
        for (int i = 0; i < 32; i++) {
            System.out.print(arr[3][i] + " ");
        }
        System.out.println();

        // Print ac_1
        System.out.print("ac_1: ");
        for (int i = 0; i < 32; i++) {
            System.out.print(arr[4][i] + " ");
        }
        System.out.println();

        // Print fc_2
        System.out.print("fc_2: ");
        for (int i = 0; i < 32; i++) {
            System.out.print(arr[5][i] + " ");
        }
        System.out.println();

        System.out.println("Eval After Centipawn Conversion: " + arr[6][0]);
        System.out.println("Big Net Used: " + (arr[6][1] == 0));
        System.out.println("Bucket: " + (arr[6][2]+1));


        //150/127
    }
}