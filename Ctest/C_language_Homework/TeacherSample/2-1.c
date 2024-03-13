struct student *queryNode(struct student *head, int xh)
{
	struct student *p;
	for(p = head;p != NULL;p = p->next)
	{
		if(p->xh == xh)
		{
			break;
		}
	}
	return p;		
}




struct student *delNode(struct student *head, struct student *delNode)
{
	struct student *p1,*p2;
	p2=head;
	//三种情况：1、首结点符合要求，2、尾结点符合要求，3，中间节点符合要求
	for(p1 = head;p1 != NULL;p1 = p1->next) 
	{
	    
		if(p1 == delNode)
	   	  {
	   	  	 if(p1 == head) //1、首结点符合要求
	   	  	 {
	   	  	 	head = delNode->next;
				free(delNode); //释放
	   	  	 	break;
			  }
			 else if(p1->next == NULL) //2、尾结点符合要求
			 {
			 	p2->next = NULL;
				free(delNode); //释放			 	
			 }
			 else //3，中间节点符合要求
			 {
			    
				p2->next = p1->next;
			    free(delNode);			  
			    break;
			 } 		   
		  }
		  else //不匹配 
		  {
		   	p2 = p1;
		   	printf("go\n");
		  }		   	
	   }
	   return head; 
}
