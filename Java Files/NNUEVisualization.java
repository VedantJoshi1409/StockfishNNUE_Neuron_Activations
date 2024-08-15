import java.io.File;

public class NNUEVisualization {
    static {
        File dll = new File("visualization.dll");
        System.load(dll.getAbsolutePath());
    }

    public static native void init(String bigNet, String smallNet);

    public static native int[][] getNeurons(String fen);
}
