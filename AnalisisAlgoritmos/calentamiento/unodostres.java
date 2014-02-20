
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
           
           String[] num={"uno","dos","tres"};
        String s;
        int n = Integer.parseInt(read.readLine());
        while (n-- > 0) {
            int iuno=2,idos=2,itres=2;
             String x= read.readLine();
             int i=0;
             if(x.length()==3){
                 i=0;
                while(i<x.length()){
                    
                    if(x.charAt(i)!=num[0].charAt(i)) iuno--;           
                    if(x.charAt(i)!=num[1].charAt(i)) idos--;
                    i++;
                }
                   System.out.println((iuno>0)?"1":"2");
             }else{
//                 i=0;
//                 while(i<x.length()){
//                    if(x.charAt(i)!=num[2].charAt(i)) idos--;
//                    i++;
//                }
             
                 System.out.println("3");
             }
             
             
        }

    }
}