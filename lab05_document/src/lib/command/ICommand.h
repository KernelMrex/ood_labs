#ifndef LAB05_DOCUMENT_ICOMMAND_H
#define LAB05_DOCUMENT_ICOMMAND_H

class ICommand
{
public:
	virtual void Execute() = 0;

	virtual ~ICommand() = default;
};

#endif // LAB05_DOCUMENT_ICOMMAND_H
