// Huihong Zheng
//csci335 hw#2
#ifndef CSCI335_HOMEWORK2_POINTS2D_H_
#define CSCI335_HOMEWORK2_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project 
{
    // Place comments that provide a brief explanation of this class,
    // and its sample usage.
    // It's a 2 dimension Array pointer points to give a point
    // Object can be use to add 2D dimension points together
    // Take Input in one line
    template<typename Object>
    class Points2D 
    {
    public:
        // Default "big five" -- you have to alter them for your assignment.
        // That means that you will remove the "= default" statement.
        //  and you will provide an implementation for it.

        // Zero-parameter constructor. 
        //Set size to 0.
        //Set pointer to null
        Points2D():sequence_(nullptr), size_(0) 
        {
        }

        // Copy-constructor.    
        // allocate new space for sequence
        // assign the rhs sequence into new sequence
        Points2D(const Points2D &rhs): size_(rhs.size_) 
        {       
            sequence_ = new std::array<Object, 2>[size_]; 
            for (unsigned int i = 0; i < size_; i++)
            {
            	for (unsigned int j = 0 ; j< 2;j++)  
            	{
            		sequence_[i][j]=rhs.sequence_[i][j]; 
                }
            }
        }

        // Copy-assignment. If you have already written
        // the copy-constructor and the move-constructor
        // you can just use:
        // {
        // Points2D copy = rhs; 
        // std::swap(*this, copy);
        // return *this;
        // }
        
        //copy assignment
        //@copy = make a copy of right hand side 
        //@swap current with copy
        //@return = return copy of rhs 
        Points2D& operator=(const Points2D &rhs) 
        {
            Points2D copy = rhs; 
            std::swap(*this, copy); 
            return *this; 
        }

        // Move-constructor. 
        //initalize the data members from rhs
        //release the data pointer on the rhs 
        Points2D(Points2D &&rhs) : sequence_(rhs.sequence_), size_(rhs.size_) 
        {
        	rhs.sequence_ = nullptr; //set back to pointing nothing
        	rhs.size_ = 0; //set back to 0
        }

        // Move-assignment.
        // Just use std::swap() for all variables.
        // @return reference to this object
        Points2D& operator=(Points2D &&rhs)
        {	
        	std::swap(sequence_,rhs.sequence_); 
        	std::swap(size_,rhs.size_);
        	return *this; 
        }

        //destructor
        //free the memory/ destroy object 
        //then points to null
        ~Points2D() 
        {
            if (sequence_ != nullptr) 
            {
                delete[]sequence_;
                sequence_= nullptr;  
            }

        }
        // End of big-five.

        // One parameter constructor.
        // item is a point like {1,2} = 1 sequence 
        // @size_ set to one point
        // allocate space for 1 sequence item
        Points2D(const std::array<Object, 2>& item) 
        {
            size_ = 1;  
            sequence_ = new std::array<Object, 2>{item};
        }

        // Read a chain from standard input.
        void ReadPoints2D() 
        {
        
            // Part of code included (without error checking).
            std::string input_line;
            std::getline(std::cin, input_line);
            std::stringstream input_stream(input_line);
            if (input_line.empty()) return;
            int size_of_sequence;
            input_stream >> size_of_sequence;// Read size of sequence (an integer).
            size_ = size_of_sequence; // set size_ to size of sequence
            sequence_ = new std::array<Object,2> [size_of_sequence];   // Allocate space for sequence

	        int counter = 0 ; 
            Object token; 
            //Read the points and store them
            //@counter to keep in track of 
            //@i%2 to store array pointers of 2D points ([0][0], [0][1]) and continues...
            for (int i = 0; input_stream >> token; ++i) 
            {
         	    sequence_[counter][i%2] = token; 
        	    if( i%2 ==1) //increase the counter by 1 if [0][0] [0][1] has reached 
        	    {
			        counter = counter +1; 
		        }        		
      
            } 
            std::cout <<"\n"; // skip a line

        }

        //@returns the size of sequence
        size_t size() const 
        {
            return size_; 
        } 

        // @location: an index to a location in the given sequence.
        // @returns the point at @location.
        //@Reachable: keep in track the location is accessable
        // const version.
        // abort() if out-of-range.
        const std::array<Object, 2>& operator[](size_t location) const 
        {
            bool Reachable = (( location >= 0 ) && ( location <= size_)); 
            if(Reachable) 
            {
                return sequence_[location]; 
            }
            else 
            {
                std::abort();
            }
        }

        //  @c1: A sequence.
        //  @c2: A second sequence.
        //  @return their sum. If the sequences are not of the same size, append the
        //    result with the remaining part of the larger sequence.
        //@ result = store the larger sequence after adding them
        friend Points2D operator+(const Points2D &c1, const Points2D &c2) 
        {
            int Sequence1 = c1.size(); 
            int Sequence2 = c2.size(); 
            Points2D result;
            if( Sequence2 < Sequence1) 
            {
            	std::array<Object,2>* CreateHolder = new std::array<Object,2>[Sequence1]; 
            	{
                    //add the 2D coordinate points that both sequence share of size
            		for (int x = 0; x<Sequence2; x++)
            		{
            		  for(int j= 0 ; j<2; j++)
            		  {
            		  	CreateHolder[x][j] = c1[x][j] + c2[x][j];
            		  }
            		}
                    //add the leftover of larger portion 
            		for (int x = Sequence2; x<Sequence1; x++) 
            		{
            		  for(int j= 0 ; j<2; j++) 
            		  {
            		  	CreateHolder[x][j] = c1[x][j]; 
            		  }
            		}
            	}          	
            	result.sequence_ = CreateHolder; 
            	result.size_= Sequence1; 
            	return result;
            	
              } 	
            else
            {
            	std::array<Object,2>*CreateHolder= new std::array<Object,2>[Sequence2]; 
            	{	
                    //add the 2D coordinate points that both sequence share of size
            		for (int x = 0; x<Sequence1; x++) 
            		{
            		  for(int j= 0 ; j<2; j++)
            		  {
            		  	CreateHolder[x][j] = c1[x][j] + c2[x][j];  

            		  }
            		 }
                     //add the leftover of larger portion 
            		for (int x = Sequence1; x<Sequence2; x++) 
            		{
            		  for(int j= 0 ; j<2; j++)
            		  {
            		  	CreateHolder[x][j] = c2[x][j];	
            		  }
            		 }
            	}
            	result.sequence_ = CreateHolder; 
            	result.size_= Sequence2; 
            	return result;       
            }    
        }

        // Overloading the << operator.
        //@out: return the 2D coordinate points of the sequences
        friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2d) 
        {
        	int ReadSize= some_points2d.size();
        	if ( ReadSize != 0 ) 
        	{
        		int i = 0; 
        		while(i < ReadSize) 
        		{
				    out <<"("<< some_points2d.sequence_[i][0]<< ", "<<some_points2d.sequence_[i][1]<<") ";
                    i = i +1; 
        		}
        	}
        	else
        	{
        		out<<"()"; 
        	}
        	out<<std::endl;
        	return out;
        }

    private:
        //@sequence is a 2D Point
        //@size_ is size of sequence
        std::array<Object, 2> *sequence_;
        size_t size_;
    };

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK2_POINTS2D_H_
