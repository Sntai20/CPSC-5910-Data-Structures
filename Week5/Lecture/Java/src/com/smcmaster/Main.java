package com.smcmaster;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.TreeSet;

public class Main {
    private static Random rnd = new Random();

    public static void main(String[] args) {
        for (int i = 1; i < 100000; i = i + 1000) {
            //runFindTest(i, 1000);
            //runInsertTest(i, 1000);
            runRemoveTest(i, 1000);
        }
    }

    private static void init(TreeSet<Integer> tree, ArrayList<Integer> array, ArrayList<Integer> numbers, int size) {
        for (int i = 0; i < size; i++) {
            numbers.add(rnd.nextInt());
        }

        Collections.shuffle(numbers);

        for (int val : numbers) {
            tree.add(val);
            array.add(val);
        }
    }

    private static void runFindTest(int size, int trials) {
        TreeSet<Integer> tree = new TreeSet<>();
        ArrayList<Integer> array = new ArrayList<>();
        ArrayList<Integer> numbers = new ArrayList<>();
        init(tree, array, numbers, size);

        long totalTreeNanos = 0;
        long totalArrayNanos = 0;
        for (int trial = 0; trial < trials; trial++) {
            int toFind = numbers.get(rnd.nextInt(size));
            long start = System.nanoTime();
            boolean found = tree.contains(toFind);
            totalTreeNanos += (System.nanoTime() - start);

            start = System.nanoTime();
            found = array.contains(toFind);
            totalArrayNanos += (System.nanoTime() - start);
        }

        System.out.println("" + size + "\t" + totalTreeNanos/trials + "\t" + totalArrayNanos/trials);
    }

    private static void runInsertTest(int size, int trials) {
        TreeSet<Integer> tree = new TreeSet<>();
        ArrayList<Integer> array = new ArrayList<>();
        ArrayList<Integer> numbers = new ArrayList<>();
        init(tree, array, numbers, size);

        long totalTreeNanos = 0;
        long totalArrayNanos = 0;
        for (int trial = 0; trial < trials; trial++) {
            int toAdd = rnd.nextInt();
            long start = System.nanoTime();
            tree.add(toAdd);
            totalTreeNanos += (System.nanoTime() - start);

            start = System.nanoTime();
            array.add(toAdd);
            totalArrayNanos += (System.nanoTime() - start);
        }

        System.out.println("" + size + "\t" + totalTreeNanos/trials + "\t" + totalArrayNanos/trials);
    }

    private static void runRemoveTest(int size, int trials) {
        TreeSet<Integer> tree = new TreeSet<>();
        ArrayList<Integer> array = new ArrayList<>();
        ArrayList<Integer> numbers = new ArrayList<>();
        init(tree, array, numbers, size);

        long totalTreeNanos = 0;
        long totalArrayNanos = 0;
        for (int trial = 0; trial < trials; trial++) {
            int toRemove = numbers.get(rnd.nextInt(size));
            long start = System.nanoTime();
            tree.remove(toRemove);
            totalTreeNanos += (System.nanoTime() - start);

            start = System.nanoTime();
            array.remove((Integer) toRemove);
            totalArrayNanos += (System.nanoTime() - start);
        }

        System.out.println("" + size + "\t" + totalTreeNanos/trials + "\t" + totalArrayNanos/trials);
    }
}
