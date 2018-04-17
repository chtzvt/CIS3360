/*
 * CIS3360 - Spring 2018
 * Security in Computing - Assignment 2
 * Submitted by: Charlton Trezevant
 */

import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class ChecksumTester {
  
  private static class ChecksumCalculator {
    
    public static class Bitmath {
      public static int calculate(byte[] input, int sum_size){
        int[] sum_values = chunkBytes(input, sum_size);
        int sum = 0;
        
        for(int val : sum_values)
          sum += val;
        
        return sum & (int)(Math.pow(2, sum_size) - 1);
        
      }
      
      public static int[] chunkBytes(byte[] input, int sum_size){
        int subgroup_width = sum_size / 8;
        int[] values = new int[input.length / subgroup_width];
        int j = 0;
        
        for(int i = 0; i < input.length; i += subgroup_width){
          switch(sum_size){
            case 16:
              values[j] = (int) ( (short) ((input[i] << 8) | (input[i + 1] & 0xFF)) ); //this is the array of bytes to actually sum up
              break;
              
            case 32:
              values[j] = ((input[i] << 24) | (input[i + 1] << 16) | (input[i + 2] << 8) | input[i + 3]) & 0xFFFFFFFF;
              break;
              
            default: // default: assumes MASK_8_BIT
              values[j] = (int)(input[i] & 0xFF);
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

  
  public static void main(String[] args){
    
    String testString = "AAAAAAAAAA" + System.lineSeparator();
    String testString_16 = "AAAAAAAAAA" + System.lineSeparator() + 'X';
    
    ChecksumCalculator checksum = new ChecksumCalculator();
    
    int sum_8 = checksum.calcFromString(testString, 8);
    System.out.printf("Sum 8: %s%n", Integer.toHexString(sum_8));
    
    int sum_16 = checksum.calcFromString(testString_16, 16);
    System.out.printf("Sum 16: %s%n", Integer.toHexString(sum_16));

  }
  
}
