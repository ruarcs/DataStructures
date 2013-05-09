/**
 * 
 */
package interfaces;

import java.util.Iterator;

/**
 * @author Ruarc.Sorensen
 *
 */
public interface PriorityQueue<Item> extends Iterable<Item>
{

	class DataElement<Item>
	{
		int priority;
		Item item;
	}
	
	public void push(int priority, Item item);
	
	public Item pop();
	
	public int highestPriority();
	
	public int lowestPriority();
	
	public boolean isEmpty();
	
	public Item peek();
	
	public Iterator<Item> iterator();
}
