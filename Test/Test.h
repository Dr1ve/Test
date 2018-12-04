#pragma once

#include <QtWidgets/QWidget>
#include <QNetworkAccessManager>
#include <QPlainTextEdit>

class Test : public QWidget
{
	Q_OBJECT

public:
	Test(QWidget *parent = Q_NULLPTR);

private slots:
	void replyFinished(QNetworkReply*);

private:
	QNetworkAccessManager manager;

	QPlainTextEdit *text;
};
