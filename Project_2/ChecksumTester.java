/*
 * CIS3360 - Spring 2018
 * Security in Computing - Assignment 2
 * Submitted by: Charlton Trezevant
 */

import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class ChecksumTester {
  
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
    
    String testString_8 = "AAAAAAAAAA" + System.lineSeparator();
    String testString_16 = "AAAAAAAAAA" + System.lineSeparator() + 'X';
    String testString_32 = "AAAAAAAAAAAAAAAAA" + System.lineSeparator() + "XX";
    
    ChecksumCalculator checksum = new ChecksumCalculator();
    
    int sum_8 = checksum.calcFromString(testString_8, 8);
    System.out.printf("Sum 8 of %s: %s%n", testString_8, Integer.toHexString(sum_8));
    
    int sum_16 = checksum.calcFromString(testString_16, 16);
    System.out.printf("Sum 16 of %s: %s%n", testString_16, Integer.toHexString(sum_16));
    
    int sum_32 = checksum.calcFromString(testString_32, 32);
    System.out.printf("Sum 132 of %s: %s%n", testString_32, Integer.toHexString(sum_32));

  }
  
}
