/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author jeison
 */
import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(read.readLine());
        while (n-- > 0) {
            int t = Integer.parseInt(read.readLine());
            String x = read.readLine();

            TreeMap<String, Integer> h = new TreeMap<>();

            h.put("SSS", 0);
            h.put("SSC", 0);
            h.put("SCS", 0);
            h.put("SCC", 0);
            h.put("CSS", 0);
            h.put("CSC", 0);
            h.put("CCS", 0);
            h.put("CCC", 0);

            for (int i = 0; i < x.length() - 2; i++) {
                String a = x.substring(i, i + 3);
                h.put(a, h.get(a) + 1);

            }

            Iterator iter = h.descendingMap().entrySet().iterator();
            Map.Entry e;

            System.out.print(t);
            while (iter.hasNext()) {
                e = (Map.Entry) iter.next();

                System.out.print(" " + e.getValue());
            }
            System.out.println("");
        }

    }

}
