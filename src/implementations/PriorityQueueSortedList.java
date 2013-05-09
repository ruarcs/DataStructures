/**
 * 
 */
package implementations;

import java.util.Iterator;

import interfaces.PriorityQueue;

/**
 * @author Ruarc.Sorensen
 *
 */
public class PriorityQueueSortedList<Item extends Comparable<Item>> implements PriorityQueue<Item>
{
	/******************************************************
	 * 	MEMBER VARIABLES
	 ******************************************************/
	private Node tail;
	private int size;

	
	/******************************************************
	 * 	METHODS
	 ******************************************************/
	
	public PriorityQueueSortedList()
	{
		this.tail = null;
		this.size = 0;
	}
	
	@Override
	public void push(Item item) 
	{		
		Node temp = this.tail;
		int count = 1;
		
		// Run the length of the array.
		// When we get to an item that is less in priority than the 
		// one we're pushing then insert after it.		
		
		while(count <= this.size)
		{
			if(less(temp.data, item))
			{
				//Insert item after temp.
				Node newnode = new Node(item);
				
				newnode.previous = temp;
				newnode.next = temp.next;
				
				temp.next.previous = newnode;
				
				return;
			}
			
			temp = temp.previous;
			count++;
		}
		
		// Should NOT get to here!
		return;
	}

	@Override
	public Item pop() 
	{
		// TODO Auto-generated method stub
		Node temp = this.tail;
		this.tail = this.tail.previous;
		return temp.data;
	}

	@Override
	public int size() 
	{
		return this.size;
	}

	@Override
	public boolean isEmpty() 
	{
		return (this.size == 0);
	}

	@Override
	public Item peek() 
	{
		// Keep tail as is.
		return this.tail.data;
	}

	/******************************************************
	 * 	PRIVATE METHODS
	 ******************************************************/
	
	private boolean less(Item item1, Item item2) 
	{
		return (item1.compareTo(item2) < 0);
	}
	
	/******************************************************
	 * 	TESTING
	 ******************************************************/
	
	public static void main(String[] args)
	{
		System.out.println("Hello, world!");
	}
	
	/******************************************************
	 * 	INNER CLASSES
	 ******************************************************/	
	
	private class Node
	{
		public Node(Item item) 
		{
			previous = null;
			next = null;
			data = item;
		}
		
		private Node previous;
		private Node next;
		private Item data;
	}
}
