/*
 * OSThreadEx.h
 *
 *  Created on: Feb 4, 2015
 *      Author: dinglinhui
 */

#ifndef OSTHREADEX_H_
#define OSTHREADEX_H_
#include "OSDispatcherEx.h"
#include "OSMessageBase.h"
#include "OSThread.h"

namespace osext {

class OSDispatcherEx;
class OSThreadEx: public OSThread, public OSMessageBase {
public:
	OSThreadEx();
	virtual ~OSThreadEx();

	virtual OSRet Start();

	OSDispatcherEx* GetDispatcher() const {
		return m_pParent;
	}
	void SetDispatcher(OSDispatcherEx* pParent);

protected:
	virtual OSRet Run() override;

	OSThreadEx* m_pNext;

private:
	OSDispatcherEx* m_pParent;

	friend class OSDispatcherEx;
};

} /* namespace osext */

#endif /* OSTHREADEX_H_ */
