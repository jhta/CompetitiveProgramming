import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
	
	
	public static long SA(String x, String y){
                        int xs=x.length();
                        int ys=y.length();
                        long M[][]=new long[xs+1][ys+1];
                        for (int i = 0; i <= xs; i++) 
                            M[i][0]=0;
                        for (int i = 0; i <= ys; i++) 
                            M[0][i]=0;
                        
                       for (int i = 1; i <= xs; i++) {
                           for (int j = 1; j <= ys; j++) {
                               long mini;
                               if(x.charAt(i-1)==y.charAt(j-1)){
                                   mini=M[i-1][j-1]+1;
                               }else{
                                   mini=M[i-1][j-1];
                               }
                               long miny=Math.max(M[i][j-1], M[i-1][j]);
                               M[i][j]=Math.max(miny, mini);
                           }
                        }
                       
                        return M[xs][ys];
                }
	
	public static void main(String[] args) throws IOException {
		
                    BufferedReader read= new BufferedReader(new InputStreamReader(System.in));

                    while(true){
                        String x=read.readLine();
                        if(x.equals("#")) break;
                        String y=read.readLine();
                        long maxi=Math.max(x.length(), y.length());
                        System.out.println("Se pueden visitar a lo sumo "+(SA(x, y))+" ciudades");
                        
                    }
                    
                    
	}

}
