/*
 * CIS3360 - Spring 2018
 * Security in Computing - Assignment 2
 * Submitted by: Charlton Trezevant and Alexander Cote
 */

import java.util.*;
import java.io.*;

public class checksum {
  
  // I'm the operator with my Checksum calculator
  private static class ChecksumCalculator {
    
    public static class Bitmath {
      public static int calculate(byte[] input, int sum_size){
        int[] sum_values = chunkBytes(input, sum_size);
        int sum = 0;
        
        for(int val : sum_values)
          sum += val;
        
        return sum & (int)(Math.pow(2, sum_size) - 1);
        
      }
      
      private static int[] chunkBytes(byte[] input, int sum_size){
        int subgroup_width = sum_size / 8;
        int[] values = new int[input.length / subgroup_width];
        int j = 0;
        
        for(int i = 0; i < input.length; i += subgroup_width){
          switch(sum_size){
            case 16:
              values[j] = (int)((short)((input[i] << 8) | (input[i + 1] & 0xFF)));
              break;
              
            case 32:
              values[j] = ((input[i] << 24) | (input[i + 1] << 16) | (input[i + 2] << 8) | input[i + 3]) & 0xFFFFFFFF;
              break;
              
            default:
              values[j] =input[i] & 0xFF;
          }
          
          j++;
        }
        
        return values;
        
      }
    }
      
    public static int calcFromString(String input, int sum_size){
      return Bitmath.calculate(input.getBytes(), sum_size);
    }
      
    public static int calcFromBytes(byte[] input, int sum_size){
      return Bitmath.calculate(input, sum_size);
    }
    
  }
  

  // manages retrieval of source texts from the filesystem
  private static class FileHandler {
    private FileHandler(){
      super();
    }
    
    private static String readFile(String filename){
        
      String file_line = "";
      String file_contents = "";
      
      try {
        FileReader reader = new FileReader(filename);
        BufferedReader buffer = new BufferedReader(reader);
        
        while((file_line = buffer.readLine()) != null) {
          file_contents += file_line + System.lineSeparator();
        }
        
        buffer.close();
      }
      
      catch(IOException e) {
        System.out.printf("*** An error was encountered while loading the file: ***%n");
        e.printStackTrace();
      }

      return file_contents;
      
    }
    
  }
  
  // Cleans/pads/formats input files
  private static class InputFormatter {
    public InputFormatter(){
      super();
    }
    
    public static String addPadding(String plaintext, int mod){
      // Compute the total number of times the key fits into the plaintext, rounding up
      int key_padding = (plaintext.length() / mod) + ((plaintext.length() % mod == 0) ? 0 : 1);
      // Padding amount = amount to pad plaintext to fit the key into it evenly
      int padAmount = (key_padding * mod) - plaintext.length();

      for(int i = 0; i < padAmount; i++)
        plaintext += 'X';
      
      return plaintext;
    }
    
  }
  
  // handles program output display (80 column block formatting, etc)
  private static class OutputFormatter {
    private static int OUTPUT_LINE_LENGTH = 80;
    
    private OutputFormatter(){
      super();
    }
    
    public static void printBlockOutput(String input){
      int i = 0;
      int j = 0;
      
      while(j < input.length()){
        String fmt = "%c";
        
        if(i == (OUTPUT_LINE_LENGTH - 1)){
          fmt += "%n";
          i = 0;
        } else {
          i++;
        }
          
        System.out.printf(fmt, input.charAt(j));
        j++;
      }
    }
  }
  
  public static void main(String[] args){
        
    String file_contents = FileHandler.readFile(args[0]);
    int sum_size = Integer.parseInt(args[1]);
    
    String padded_text = InputFormatter.addPadding(file_contents, sum_size / 8);
    
    OutputFormatter.printBlockOutput(padded_text);
    
    int checksum = ChecksumCalculator.calcFromString(padded_text, sum_size);
    
    System.out.printf("sum_size: %d%n%x%n", sum_size,  checksum);
  }
  
}
