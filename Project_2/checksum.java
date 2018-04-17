/*
 * CIS3360 - Spring 2018
 * Security in Computing - Assignment 2
 * Submitted by: Charlton Trezevant
 */

import java.util.*;
import java.io.*;

public class checksum {
  
  // I'm the operator with my checksum calculator
  private static class ChecksumCalculator {
    private static int[] SIZES_AVAILABLE = {8, 16, 32};
    
    // Nested class to contain all of our bitwise bean-counting
    private static class Bitmath {
      // This method, given an array of 8 bit bytes (e.g. ascii characters)
      // will generate a new array of integers that are correctly sized in proportion to
      // the size of the requested checksum. We'll use this to rearrange the individual bytes
      // in `input` into groups that are correctly sized in proportion to the size of the requested checksum.
      // As an example, a 16 bit checksum would use 2 such bytes of input at a time, while a 32 bit one
      // would use 4.
      private static int[] chunkBytes(byte[] input, int sum_size){
        int sum_val_width = sum_size / 8;
        int[] checksum_values = new int[input.length / sum_val_width];
        int j = 0;
        
        for(int i = 0; i < input.length; i += sum_val_width){
          switch(sum_size){
            case 16:
              checksum_values[j] = (int)((short)((input[i] << 8) | (input[i + 1] & 0xFF)));
              break;
              
            case 32:
              checksum_values[j] = (int)((input[i] & 0xFF) << 24) | ((input[i + 1]  & 0xFF) << 16) | ((input[i + 2] & 0xFF) << 8) | ((input[i + 3] & 0xFF) << 0);
              break;
              
            default:
              checksum_values[j] = input[i] & 0xFF;
          }
          
          j++;
        }
        
        return checksum_values;
        
      }
    }
    
    // First converts a string to an array of bytes, then calls calcFromBytes to generate a
    // checksum
    public static int calcFromString(String input, int sum_size){
      return calcFromBytes(input.getBytes(), sum_size);
    }
    
    // Given an array of bytes, this method will first generate an array of
    // appropriately wide values for the requested sum size. It will then add
    // up all the resized values, finally applying the appropriate mask for the sum size
    // provided.
    public static int calcFromBytes(byte[] input, int sum_size){
      int[] sum_values = Bitmath.chunkBytes(input, sum_size);
      int sum = 0;
      
      for(int val : sum_values)
        sum += val;
      
      return sum & (int)(Math.pow(2, sum_size) - 1);
    }
    
    // This method determines the validity of a requested check size, returning
    // false if calculations for that size have not been implemented
    public static boolean validateCheckSize(int sum_size){
      for(int i = 0; i < ChecksumCalculator.SIZES_AVAILABLE.length; i++)
        if(sum_size == ChecksumCalculator.SIZES_AVAILABLE[i])
          return true;
      
      return false;
    }
    
  }
  
  // manages retrieval of source texts from the filesystem
  private static class FileHandler {
    private FileHandler(){
      super();
    }
    
    // Given a filename, this method will return its full contents as a string
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
  
  // This class cleans, pads, and formats program input
  private static class InputFormatter {
    public InputFormatter(){
      super();
    }
    
    public static String addPadding(String plaintext, int mod){
      int key_padding = (plaintext.length() / mod) + ((plaintext.length() % mod == 0) ? 0 : 1);
      int padAmount = (key_padding * mod) - plaintext.length();

      for(int i = 0; i < padAmount; i++)
        plaintext += 'X';
      
      return plaintext;
    }
    
  }
  
  // handles program output display (specifically, 80 column block formatting)
  private static class OutputFormatter {
    private static final int OUTPUT_LINE_LENGTH = 80;
    
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
    
    // Determine the validity of the given checksum size
    int sum_size = Integer.parseInt(args[1]);
    
    if(ChecksumCalculator.validateCheckSize(sum_size) == false){
      System.err.printf("Valid checksum sizes are 8, 16, or 32%n");
      System.exit(1);
    }
    
    // Load the source text file, and pad it appropriately
    String file_contents = FileHandler.readFile(args[0]);
    String padded_text = InputFormatter.addPadding(file_contents, sum_size / 8);
    
    // Print the soure text out, honoring the 80 column formatting
    System.out.printf("%n");
    OutputFormatter.printBlockOutput(padded_text);
    System.out.printf("%n");
    
    // Calculate and print our checksum
    int checksum = ChecksumCalculator.calcFromString(padded_text, sum_size);
    System.out.print(checksum);
    System.out.printf("%2d bit checksum is %8x for all %4d chars%n", sum_size, checksum, padded_text.length());
    
    System.exit(0);
  }
  
}
