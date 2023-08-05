package com.practice;

import java.util.Scanner;

abstract class Parent{
    public Parent {
        System.out.println("Its constructor of Parent");
    }
    public void Sayhello(){
        Syztem.out.println("Hello");
    }
    abstract public void greet1();
    abstract public void greet2();
}
class child extends Parent{
    @override
    public void greet1() {
        System.out.println("Good Morning");
    }
    @override
    public void greet2() {
        System.out.println("Good Afternoon");
    }
}
class Package1
{
    public static void main(String args[])
    {
    Scanner sc = new Scanner(System.in);
        Child c = new Child();
    }
}