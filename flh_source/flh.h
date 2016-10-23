#ifndef FLH_H
#define FLH_H

#include <QMainWindow>
#include <QtNetwork/QtNetwork>

namespace Ui {
class flh;
}

class flh : public QMainWindow
{
    Q_OBJECT

public:
    explicit flh(QWidget *parent = 0);
    ~flh();

    QNetworkAccessManager *manager;
    QNetworkRequest req;

private:
    Ui::flh *ui;

public slots:
    void makeRequest();
    void readAnswer(QNetworkReply *reply);

    QByteArray hmac_sha1(const QString &key, const QString &secret);
};

#endif // FLH_H
