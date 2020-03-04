package com.company;


import java.util.Random;


public class Main {
    public static final int arr_size = 20000;
    public static final int MAGIC_NO = 9999999;


    protected static int[] arr = new int[arr_size];
    public static void main(String[] args) {
	// write your code here

        for (int i = 0; i < arr_size; i++) {
            arr[i] = new Random().nextInt()%1000000;

        }
        //replace
        int index = Math.abs(new Random().nextInt()%arr_size);
        System.out.println((index));
        arr[index] = MAGIC_NO;

        multiThreadSearch(arr);

    }

    public static int uniThreadSearch(int[] arr){
        for (int i = 0; i < arr.length; i++) {
            System.out.println(i+" : "+arr[i]);
            if(arr[i] == MAGIC_NO){
                System.out.println("unithread found :" + i);
                return 0;
            }
        }
        System.out.println("NOTFOUND");
        return -1;
    }

    public static int multiThreadSearch(int[] arr){
        int len = arr.length;

        MyThread one = new MyThread(MAGIC_NO,0, len/4);
        one.start();

        MyThread two = new MyThread(MAGIC_NO,len/4, 2*(len/4));
        two.start();

        MyThread three = new MyThread(MAGIC_NO,2*(len/4), 3*(len/4));
        three.start();

        MyThread four = new MyThread(MAGIC_NO,3*(len/4), len);
        four.start();



        return 0;
    }






//inner class
    public static class MyThread extends Thread {
        private int start;
        private int end;
        private int magicNum;

        public MyThread(int magicNum, int start, int end) {
            this.start = start;
            this.end = end;
            this.magicNum = magicNum;

        }

        @Override
        public void run() {
            //System.out.println("Hello Threaded World! I am thread number:  ");
            for (int i = start; i < end; i++) {
                System.out.println(i+" : "+arr[i]);
                if(arr[i] == magicNum) {
                    System.out.println("multithread found:"+ i);
                    System.exit(0);
                }
            }
        }
    }


}

