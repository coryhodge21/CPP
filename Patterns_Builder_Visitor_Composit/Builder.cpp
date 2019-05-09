/*
 * Created by Cory Hodge on 2019-04-05.
 *
 *
 */// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#include "Builder.h"

Builder::Builder() :
        root_(nullptr),
        numQ_(new Queue<Node *>()),
        opQ_(new Queue<Node *>()),
        tree_(new Queue<Node *>()) {
    
}

Builder::~Builder() {
    
    if (numQ_)
        delete numQ_;
    if (opQ_)
        delete opQ_;
    if (tree_)
        delete tree_;
}

/**
 * Return root_ of tree to caller
 *
 * insert special function node
 */
Node *Builder::get_root() {
    
    return this->root_;
}


/**
 * get vars from user in alphabetic order
 */
void Builder::get_variable_values(void) {
    
    if (map_.size() > 0) {
        
        // Alert user vars will be required
        std::cout << "\n\t\tPlease Enter Variable Values\n";
        
        float test_input;
        
        //move through map pairs and assign values
        for (std::map<char, float>::iterator mapIndex = this->map_.begin(); mapIndex != this->map_.end(); mapIndex++) {
            
            
            std::cout << mapIndex->first << " = ";
            std::cin >> test_input;
            
            ///TODO: Add logic to ensure input within range
            
            mapIndex->second = test_input;
            
        }
    }
}


/**
 * Assemble Q's into Composite Tree
 *
 *
 * @return Node* : pointer to root of composite tree
 */
Node *Builder::construct_tree() {
    
    while (!opQ_->is_empty() && !numQ_->is_empty()) {
        
        Node *opNode = opQ_->dequeue();
        
        
        /// LEFT POINTER SETTING
        // if the Q of previously created nodes is empty,
        if (tree_->is_empty()) {
            
            // set the opNodes LEFT Pointer
            opNode->setLptr_(numQ_->dequeue());
            
        } else {
            
            // else , attach the LEFT Pointer to current tree
            opNode->setLptr_(tree_->dequeue());
        }
        
        /// if the opQ_ is now empty terminate level
        if (opQ_->is_empty()) {
            
            /// Exception: setting Rptr here as opStack is not empty
            opNode->setRptr_(numQ_->dequeue());
            
            // push Head to tree_
            tree_->enqueue(opNode);
            continue;
            
        }// else more operators to build
        
        /// RIGHT POINTER SETTING
        // Check for Sub Tree
        if (opQ_->next()->getPrecedence_() >= opNode->getPrecedence_()) {
            
            /**
             * using recursion to build Next level of tree
             * upon return its RIGHT Pointer will contain
             * Root of SubTree
             */
            opNode->setRptr_(construct_tree());
            
            // push to Node Q to await more operators
            tree_->enqueue(opNode);
            
            continue;
            
        } else {
            /// Precedence ( opQ_->top() ) < Precedence ( opNode )
            // End Sub Tree / Terminate Level
            opNode->setRptr_(numQ_->dequeue());
            return opNode;
        }
        
    } // End while numQ_ != empty()
    
    // Lastly, pass root
    root_ = tree_->dequeue();
    
    // optional return root, but builder does not use this
    return get_root();
    
}


/**
 * Build expression tree from the user inputted string::expression
 *  and return Node * pointing too root of tree
 *
 *  this builder appends a special function node to the top of the tree
 *    this allows visitor to control the flow of reading and evaluating the tree
 *
 * @return Node* : pointer to root of composite tree
 * @param expression : string algebraic expression
 */
Node *Builder::build_expression_tree(std::string expression) {
    
    // cycle input , construct nodes, fill Qs
    construct_node_Qs(expression);
    
    ///TODO:: impliment control logic for assosicating variables to their map key values, or set var value field
    /* get variable values from user in alphabetic order */
    //get_variable_values();
    
    /* recursively build  tree*/
    construct_tree();
    
    // test: append special function to tree
    Node *eval_node = this->build_eval_node('!');
    eval_node->setLptr_(this->root_);
    this->root_ = eval_node;
    
    /* return tree */
    return this->root_;
}


/**
 * cycle input
 * create nodes for each element
 *  storing variables in map
 * append operators and numbers in separate q's
 *  expression remains as standard infix'ed
*/
void Builder::construct_node_Qs(std::string expression) {
    
    int i = 0;
    
    while (expression[i]) {
        
        
        switch (expression[i]) {
            
            case ' ':
                // skip spaces
                i++;
                break;
                
                
                /**      expression symbol is an Operator    */
            
            case '+':
                opQ_->enqueue(this->build_add_node(expression[i]));
                i++;
                break;
            
            case '-':
                opQ_->enqueue(this->build_sub_node(expression[i]));
                i++;
                break;
            
            case '*':
                opQ_->enqueue(this->build_mul_node(expression[i]));
                i++;
                break;
            
            case '/':
                opQ_->enqueue(this->build_div_node(expression[i]));
                i++;
                break;
            
            case '%':
                opQ_->enqueue(this->build_mod_node(expression[i]));
                i++;
                break;
            
            case '(':
                opQ_->enqueue(this->build_L_par_node(expression[i]));
                i++;
                break;
            
            case ')':
                opQ_->enqueue(this->build_R_par_node(expression[i]));
                i++;
                break;
                
                
                /**  expression symbol is a number     */
            
            
            case '0':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '1':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '2':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '3':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '4':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '5':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '6':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '7':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '8':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
            
            case '9':
                numQ_->enqueue(this->build_number_node(expression[i]));
                i++;
                break;
                
                
                /**
                 * expression symbol is a Variable
                 *  treat it like a number and map
                 *  the symbol for later assignment
                */
            default:
                
                /// add this symbol to the map
                std::pair<char, float> var;
                var.first = expression[i];
                this->map_.insert(var);
                
                /// create num node
                numQ_->enqueue(this->build_var_node(expression[i]));
                i++;
                break;
        }
        
    }
    
}



/**
 *              Build Parts for Algebraic Expression
 */

/// Number
Node *Builder::build_number_node(char symbol) {
    
    return new Num_Node(symbol, NUMBER_NODE_PRECEDENCE);
}

/// Add
Node *Builder::build_add_node(char symbol) {
    
    return new Add_Node(symbol, ADD_NODE_PRECEDENCE);
}

///Subtract
Node *Builder::build_sub_node(char symbol) {
    
    return new Sub_Node(symbol, SUB_NODE_PRECEDENCE);
}

/// Multiply
Node *Builder::build_mul_node(char symbol) {
    
    return new Mul_Node(symbol, MUL_NODE_PRECEDENCE);
}

/// Divide
Node *Builder::build_div_node(char symbol) {
    
    return new Div_Node(symbol, DIV_NODE_PRECEDENCE);
}

/// Modulus
Node *Builder::build_mod_node(char symbol) {
    
    return new Mod_Node(symbol, MOD_NODE_PRECEDENCE);
}

/// Left parenthesis
Node *Builder::build_L_par_node(char symbol) {
    
    return new Par_L_Node(symbol, L_PAR_NODE_PRECEDENCE);
}

/// Right Parenthesis
Node *Builder::build_R_par_node(char symbol) {
    
    return new Par_R_Node(symbol, R_PAR_NODE_PRECEDENCE);
}

/// Variable
Node *Builder::build_var_node(char symbol) {
    
    return new Var_Node(symbol, VAR_NODE_PRECEDENCE);
}

/// Special Functions
Node *Builder::build_eval_node(char symbol) {
    
    return new Eval_Node(symbol, SPF_PRECEDENCE);
}