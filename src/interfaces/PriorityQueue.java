/**
 * 
 */
package interfaces;

/**
 * @author Ruarc.Sorensen
 *
 */
public interface PriorityQueue<Item>
{

	class DataElement<Item>
	{
		int priority;
		Item item;
	}
	
	void push(int priority, Item item);
	
	Item pop();
	
	int highestPriority();
	
	int lowestPriority();
	
	boolean isEmpty();
}
