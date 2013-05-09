/**
 * 
 */
package interfaces;

/**
 * @author Ruarc.Sorensen
 *
 */
public interface PriorityQueue<Item extends Comparable<Item>>
{
	public void push(Item item);
	
	public Item pop();
	
	public int size();
	
	public boolean isEmpty();
	
	public Item peek();
}
