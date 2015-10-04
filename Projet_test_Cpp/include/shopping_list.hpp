#ifndef SHOPPING_LIST_HPP
#define SHOPPING_LIST_HPP

#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Article {

	// Attributs :
protected:
	int _quantity;

	string _unit;
	string _description;

	// Pointeur vers catégorie d'articles (division)

// Status flags :
private:
	bool _isInit;

// Méthodes :
public:
	Article();
	Article(	const int quant, 
				const string unit,
				const string desc);
	~Article();

	// Setters
	bool setQuantity(const int );
	bool setUnit(const string );
	bool setDescription(const string );

	// Getters
	int getQuantity();
	string getUnit();
	string getDescription();

	// Init
	virtual bool init(	const int , 
						const string , 
						const string );

};

class Division {

// Attributs :
protected: 


// Méthodes :

};

class ShoppingPool {

// Attributes :

protected:
	vector< Article > _ArticlePool;
	vector< Division > _DivisionPool;

private:


// Members :

public:

protected:


};

class ShoppingHistory: public ShoppingPool{



};

#endif
