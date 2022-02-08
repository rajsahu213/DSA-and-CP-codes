import java.awt.*;
import java.util.*;
import java.io.*;
import java.lang.*;

public abstract class Abstractclass{
    protected int x;
    public abstract void print();
    public void setX(int a)
    {
        x=a;
    }
    public Abstractclass()
    {
        x=0;
    }
}