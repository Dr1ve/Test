#include "Test.h"

#include <QVBoxLayout>
#include <QNetworkReply>

Test::Test(QWidget *parent)
	: QWidget(parent),
	text(new QPlainTextEdit)
{
	QVBoxLayout *lay = new QVBoxLayout;
	setLayout(lay);

	connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
	manager.get(QNetworkRequest(QUrl("https://ya.ru/")));

	lay->addWidget(text);
}

void Test::replyFinished(QNetworkReply *reply)
{
	if (reply->error())
	{
		qDebug() << "ERROR!";
		qDebug() << reply->errorString();
	}
	else
	{
		qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
		qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
		qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
		qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
		qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

		text->setPlainText(QString(reply->readAll()));
	}

	reply->deleteLater();
}