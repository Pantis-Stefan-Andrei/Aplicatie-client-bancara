#pragma once
#include "irequest.h"
#include "requestamenda.h"
#include "requestdelete.h"
#include "requestdeschidere.h"
#include "requestlogin.h"
#include "requestregister.h"
#include "requestvirament.h"
#include "requestvizualizare.h"
#include "requestcard.h"
namespace FactoryRequest
{
	static irequest* FactoryRequest::factoryStaticMethod(FactoryRequest::TipRequest tip) {
		switch (tip)
		{
		case FactoryRequest::TipRequest::amenda:
			return new requestamenda();
			break;
		case FactoryRequest::TipRequest::deschidere:
			return new requestdeschidere();
			break;
		case FactoryRequest::TipRequest::rdelete:
			return new requestdelete();
			break;
		case FactoryRequest::TipRequest::inregistrare:
			return new requestregister();
			break;
		case FactoryRequest::TipRequest::login:
			return new requestlogin();
			break;
		case FactoryRequest::TipRequest::virament:
			return new requestvirament();
			break;
		case FactoryRequest::TipRequest::vizualizare:
			return new requestvizualizare();
		case FactoryRequest::TipRequest::card:
			return new requestcard();
			break;


		}
	}
}