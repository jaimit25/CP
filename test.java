
import java.io.*;
import java.util.*;
public class test {


    public static void solve(){
        System.out.println("Hello World");
    }

    public static void main(String[] args)
        throws IOException
    {
        if (System.getProperty("ONLINE_JUDGE") == null) {
 
            PrintStream ps
                = new PrintStream(new File("output.txt"));
            InputStream is
                = new FileInputStream("input.txt");
 
            System.setIn(is);
            System.setOut(ps);

           
        }

         solve();
    }
}


