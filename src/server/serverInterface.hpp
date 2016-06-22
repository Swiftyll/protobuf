class Services
{
	public:
		Services(){}
		virtual ~Services(){}		
		virtual void getNav() = 0;
		virtual void getMessage() = 0;
};