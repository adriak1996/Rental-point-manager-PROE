

# Manager of elegant clothes' rental point (CodeBlocks C++)

### 1. Assumptions ###
  - Simple console application written in C++
  - Ability to managing a sets of resources. 
	     Lists of: commodities, customers and orders.
  - Implementation of two-level inheritance. 
	     Commodity has 2 subtypes: **Suit** and **Dress**. 
		**Dress** has 1 subtype: **Wedding dress**.
  - Mechanism of serialization/deserialization connected 
	     with saving to/loading form the file.
  - Demonstration of typical scenarios contained in 
	     one sequential presentation
  - Only special operation of save will save 
	     the current condition of data to the file. 
	     THERE IS NO AUTOSAVE after running any operations.
  - Only special operation of load will load 
	     the current condition of data from the file. 
	     THERE IS NO AUTOLOAD after launching new program.
  - The code of the application contains comments to 
	     the documentation written in Polish. 
	     PLEASE IGNORE THESE COMMENTS
	
### 2. Functionality 
  Each user of application can use any of 19 operations. 
  They are listed below.
	
  - Storage operations
		- Add new commodity
		- Remove a commodity
    	- Show list of the current commodities
    	- Check whether the commodity exists in the base 
    	- Edit a commodity
		
  - Customers operations
		- Add new customer
		- Remove a customer
		- Show list of the current customers
		- Check whether the customer exists in the base 
		- Edit a customer's details
	
  - Renting services operations
		- Rent a commodity for a customer
		- Take commodity from a customer
		- Show list of the current renting services
		- Show current stats of rental point's
		- Demonstrate the tests of the rental system
		- Clear all data from the base
	
  - Saving and loading data to\from file
		-  Save current condition of data to the file
		- Load current condition of data from the file 
		 Previous condition of data will be overwritten 

  - EXIT
		- Quit the program
	
	
	
###  3. Credits
   - *el-gato*

   ###  4. Other contribution
   - Materials from the website of the course *Object-oriented programming*

____________________________________________________________________________________
*Written in Winter/Spring of the 2016*

**DO NOT USE IN COMMERCIAL PURPOSES!!!**
